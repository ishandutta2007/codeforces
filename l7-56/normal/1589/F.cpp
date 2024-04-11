#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxl = 110, maxn = 20;
char s[maxn][maxl];
int n,p,T,len[maxn],pos[maxn][maxl][2];

int id(char ch) {
	if('a' <= ch && ch <= 'z') return ch - 'a';
	if('A' <= ch && ch <= 'Z') return ch - 'A' + 26;
	return -1;
}

int Num[maxl][1 << 10],ind[60010],cntp,lst[60010],dp[60010];
struct Point {
	int c,t;
}a[60010];
vector <int> e[60010];

int num(int c, int t) {
	if(Num[c][t] == -1) return e[++cntp].clear(), a[cntp] = (Point){c, t}, Num[c][t] = cntp;
	return Num[c][t];
}

bool check(int c, int t) {
	bool flag = 0;
	for(int i = 1; i <= n; ++i)
		if(pos[i][c][(t >> (i - 1)) & 1] == -1) flag = 1;
	return flag;
}

void print(int p) {
	if(p == -1) return;
	print(lst[p]);
	if(a[p].c < 26) putchar(a[p].c + 'a');
	else putchar(a[p].c - 26 + 'A');
}

void calc() {
	queue <int> q;
	for(int i = 1; i <= cntp; ++i)
		if(ind[i] == 0) q.push(i), dp[i] = 1;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v : e[u]) {
			if(dp[u] + 1 > dp[v]) {
				dp[v] = dp[u] + 1;
				lst[v] = u;
			}
			if(--ind[v] == 0) q.push(v);
		}
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(pos, -1, sizeof pos);
		memset(dp, -1, sizeof dp);
		memset(Num, -1, sizeof Num);
		memset(ind, 0, sizeof ind);
		memset(lst, -1, sizeof lst);
		cntp = 0;
		scanf("%d", &n);
		p = (1 << n) * 52;
		for(int i = 1; i <= n; ++i) {
			scanf("%s", s[i]);
			len[i] = strlen(s[i]);
			for(int j = 0; j < len[i]; ++j) {
				if(pos[i][id(s[i][j])][0] == -1) pos[i][id(s[i][j])][0] = j;
				else pos[i][id(s[i][j])][1] = j;
			}
		}
		
		for(int c = 0; c < 52; ++c) {
			for(int t = 0; t < (1 << n); ++t) {
				if(check(c, t)) continue;
				num(c, t);
				
				for(int nc = 0; nc < 52; ++nc) {
					int nxt = 0; bool flag = 0;
					for(int i = 1; i <= n; ++i) {
						int nw = pos[i][c][(t >> (i - 1)) & 1];
						if(pos[i][nc][0] > nw) continue;
						else if(pos[i][nc][1] > nw) nxt |= (1 << (i - 1));
						else flag = 1;
					}
					if(flag) continue;
					
					e[num(c, t)].push_back(num(nc, nxt));
					ind[num(nc, nxt)]++;
				}
			}
		}
		
		calc();
		
		int ans = 0, ansp;
		for(int i = 1; i <= cntp; ++i)
			if(ans < dp[i]) ans = dp[i], ansp = i;
		
		if(ans == 0) printf("0\n\n");
		else {
			printf("%d\n", ans);
			print(ansp);
			printf("\n");
		}
	}
	return 0;
}