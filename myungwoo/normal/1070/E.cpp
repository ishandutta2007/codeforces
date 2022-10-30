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

#define MAXN 200005

int T, N, M; lld K;
int A[MAXN], B[MAXN];

int ans, anst;

bool proc(int lmt)
{
	int done = 0, cnt = 0; lld tot = 0, bef = 0;
	for (int i=1;i<=N;i++) if (A[i] <= lmt){
		if (tot+A[i] > K){ tot = 1e18; break; }
		done++; cnt++; bef += A[i]; tot += A[i];
		if (cnt == M){
			tot += bef;
			cnt = bef = 0;
		}
	}
	if (ans < done) ans = done, anst = min(K, (lld)lmt);
	return tot < 1e18;
}

int main()
{
	for (read(T);T--;){
		read(N, M, K);
		for (int i=1;i<=N;i++) read(A[i]), B[i] = A[i];
		sort(B+1, B+N+1);
		int s = 1, e = N;
		ans = 0, anst = min(K, (lld)B[N]);
		while (s <= e){
			int m = s+e >> 1;
			if (proc(B[m])) s = m+1;
			else e = m-1;
		}
		write(ans); putchar(' '), write(anst); puts("");
	}
}