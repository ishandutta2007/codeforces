#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 200005;

namespace sfxarray{
	int ord[MAXN], nord[MAXN], cnt[MAXN], aux[MAXN];
	void solve(int n, char *str, int *sfx, int *rev, int *lcp){
		int p = 1;
		memset(ord, 0, sizeof(ord));
		for(int i=0; i<n; i++) sfx[i] = i, ord[i] = str[i];
		int pnt = 1;
		while(true){
			memset(cnt, 0, sizeof(cnt));
			for(int i=0; i<n; i++) cnt[ord[min(i+p, n)]]++;
			for(int i=1; i<=n||i<=255; i++) cnt[i] += cnt[i-1];
			for(int i=n-1; i>=0; i--){
				aux[--cnt[ord[min(i+p, n)]]] = i;
			}
			memset(cnt, 0, sizeof(cnt));
			for(int i=0; i<n; i++) cnt[ord[i]]++;
			for(int i=1; i<=n||i<=255; i++) cnt[i] += cnt[i-1];
			for(int i=n-1; i>=0; i--){
				sfx[--cnt[ord[aux[i]]]] = aux[i];
			}
			if(pnt == n) break;
			pnt = 1;
			nord[sfx[0]] = 1;
			for(int i=1; i<n; i++){
				if(ord[sfx[i-1]] != ord[sfx[i]] || ord[sfx[i-1] + p] != ord[sfx[i] + p]){
					pnt++;
				}
				nord[sfx[i]] = pnt;
			}
			memcpy(ord, nord, sizeof(int) * n);
			p <<= 1;
		}
		for(int i=0; i<n; i++) rev[sfx[i]] = i;
		int h = 0;
		for(int i=0; i<n; i++){
			if(rev[i]){
				int prv = sfx[rev[i] - 1];
				while(str[prv + h] == str[i + h]) h++;
				lcp[rev[i]] = h;
			}
			if(h) h--;
		}
	}
}

int n, m;
char S[MAXN], T[MAXN];
char con[MAXN];
int fail[MAXN];
int sfx[MAXN], rev[MAXN], lcp[18][MAXN];
int F[MAXN], lg[MAXN];
int cnt[MAXN];

int getlcp(int x, int y){
	x = rev[x]; y = rev[y];
	if(x > y) swap(x, y);
	if(x == y) return n + m - sfx[x];
	int L = lg[y - x];
	return min(lcp[L][y], lcp[L][x + (1<<L)]);
}

int main(){
	scanf("%s %s", S, T);
	for(int i=1; i<MAXN; i++){
		lg[i] = lg[i-1];
		while((2 << lg[i]) <= i) lg[i]++;
	}
	n = strlen(S);
	m = strlen(T);
	for(int i=0; i<n+m; i++){
		if(i < n) con[i] = S[i];
		else con[i] = T[i - n];
	}
	sfxarray::solve(n + m, con, sfx, rev, lcp[0]);
	for(int i=1; i<18; i++){
		for(int j=1; j<n+m; j++){
			lcp[i][j] = lcp[i-1][j];
			if(j >= (1<<i)) lcp[i][j] = min(lcp[i][j], lcp[i-1][j-(1<<(i-1))]);
		}
	}
	for(int i=0; i<n; i++){
		F[i] = min(n - i, getlcp(i, n));
	}
	int p = 0;
	for(int i=1; i<m; i++){
		while(p && T[p] != T[i]) p = fail[p];
		if(T[p] == T[i]) p++;
		fail[i + 1] = p;
	}
	for(int i=1; i<=n; i++) cnt[F[i]]++;
	for(int i=1; i<MAXN; i++) cnt[i] += cnt[i-1];
	lint ret = 0;
	for(int j=1; j<=m; j++){
		if(fail[j] == 0) ret += n;
		else ret += cnt[j - fail[j] - 1];
	}
	cout << ret << endl;
}