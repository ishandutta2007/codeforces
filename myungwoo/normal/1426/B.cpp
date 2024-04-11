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

int T, N, M;

bool solve()
{
	read(N, M);
	bool all_same = 0, sym = 0;
	for (int i=1;i<=N;i++){
		int a[4];
		for (int j=0;j<4;j++) read(a[j]);
		bool t1 = 1;
		for (int j=1;j<4;j++) if (a[0] != a[j]) t1 = 0;
		if (t1) all_same = 1;
		if (a[1] == a[2]) sym = 1;
	}
	if (M&1) return 0;
	return all_same || sym;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (read(T);T--;){
		puts(solve() ? "YES" : "NO");
	}
}