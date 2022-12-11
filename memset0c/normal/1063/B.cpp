// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
	while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

#define cross(i,k) for (register int i=first[k]; i; i=last[i])
const int maxn = 2010, maxm = maxn * maxn;
int n, m, r, c, x, y;
int id[maxn][maxn], size[maxm];
char s[maxn][maxn];
int cnt, tot;
int first[maxm], to[maxm<<
2], last[maxm<<2], co[maxm<<2];
int h,t,q[maxm],L[maxm],R[maxm],ans;
bool vis[maxm];

void add_edge(int x, int y, int v) {
	to[++tot]=y,last[tot]=first[x],first[x]=tot,co[tot]=v;
}

void bfs(int s){
	h = 0, q[t = 1] = s, vis[s] = 1;
	ans += size[s];
	while (h < t) {
		int u = q[++h];
		cross(i,u) {
			int v = to[i];
			q[++t] = v, L[t] = L[h], R[t] = R[h];
			co[i] ==1 ? L[t]++ : R[t]++;
			if(vis[v] || R[t] > y || L[t] > x) {
				t--;
				continue;
			}
			vis[v]=1;
			ans += size[v];
		}
	}
}
int main() {
	scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &x, &y);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if(s[i][j] != '*' && (s[i + 1][j] == '*' || i + 1 > n)) {
				++cnt;
				int x = i;
				while (s[x][j] == '.' && x) {
					id[x][j] = cnt;
					x--;
					size[cnt]++;
				}
			}
	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= m; j++)
			if(id[i][j] && id[i][j - 1]) {
				add_edge(id[i][j], id[i][j - 1], 1);
				add_edge(id[i][j - 1], id[i][j], -1);
			}
	bfs(id[r][c]);
	print(ans, '\n');
}