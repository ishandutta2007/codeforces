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

int N;
int A[MAXN];
lld S[MAXN];

int main()
{
	read(N);
	for (int i=1;i<=N;i++) read(A[i]), S[i] = S[i-1]+A[i];
	map<lld, int> last; last[0] = 0;
	int fix = -1, ans = 0;
	for (int i=1;i<=N;i++){
		if (last.count(S[i]) && last[S[i]]+1 >= fix){
			fix = i, ans++;
		}
		last[S[i]] = i;
	}
	write(ans); putchar('\n');
}