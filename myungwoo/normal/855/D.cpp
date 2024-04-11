#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

/* Fast Integer IO */
template<typename T> inline T read(T &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<typename T, typename... Args> inline void read(T &x, Args& ...args){
	read(x); read(args...);
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define MAXN 100005

int N, Q, K;
int dep[MAXN], par[MAXN][17], up[MAXN][17];

int lca(int a, int b)
{
	if (dep[a] < dep[b]) swap(a, b);
	for (int i=17;i--;) if (dep[a]-dep[b] & 1<<i) a = par[a][i];
	if (a == b) return a;
	for (int i=17;i--;) if (par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
	return par[a][0];
}

int get_up(int n, int h)
{
	int ret = 0;
	for (int i=17;i--;) if (h&1<<i) ret += up[n][i], n = par[n][i];
	return ret;
}

int main()
{
    read(N);
	for (int i=1;i<=N;i++){
		int p, t; read(p, t);
		if (p == -1) continue;
		par[i][0] = p; up[i][0] = t;
	}
	for (int k=1;k<17;k++) for (int i=1;i<=N;i++){
		par[i][k] = par[par[i][k-1]][k-1];
		up[i][k] = up[par[i][k-1]][k-1]+up[i][k-1];
	}
	for (int i=1;i<=N;i++) dep[i] = dep[par[i][0]]+1;
	for (read(Q);Q--;){
		int t, a, b; read(t, a, b);
		int c = lca(a, b);
		if (!c || a == b) puts("NO");
		else if (t == 1){
			if (c == a && get_up(b, dep[b]-dep[a]) == 0) puts("YES");
			else puts("NO");
		}else{
			if (c != b && get_up(a, dep[a]-dep[c]) == 0 && get_up(b, dep[b]-dep[c]) == dep[b]-dep[c]) puts("YES");
			else puts("NO");
		}
	}
}