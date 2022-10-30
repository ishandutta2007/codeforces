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

#define MAXN 300005

int N, Q;
bool vis[MAXN], fliped[19];

struct NODE{
	NODE(): sum(0) { memset(nxt, 0, sizeof(nxt)); }
	int sum;
	NODE *nxt[2];
} *root;

void add(int v)
{
	NODE *now = root;
	for (int i=19;i--;){
		bool b = v&1<<i;
		if (!now->nxt[b]) now->nxt[b] = new NODE();
		now = now->nxt[b];
		now->sum++;
	}
}

int get()
{
	NODE *now = root;
	int ret = 0;
	for (int i=19;i--;){
		int sz = 1<<i;
		if (now->nxt[fliped[i]] && now->nxt[fliped[i]]->sum == sz){
			ret ^= 1<<i;
			now = now->nxt[!fliped[i]];
		}else now = now->nxt[fliped[i]];
		if (!now) return ret;
	}
	return ret;
}

int main()
{
	read(N, Q);
	root = new NODE();
	for (int i=1;i<=N;i++){
		int v; read(v);
		if (!vis[v]) vis[v] = 1, add(v);
	}
	while (Q--){
		int v; read(v);
		for (int i=19;i--;) if (v&1<<i) fliped[i] ^= 1;
		write(get()); puts("");
	}
}