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

const int MOD = 1e6 + 3;
int N = 12;
int A[12][13];

inline int pow(int n, int k)
{
	int ret = 1;
	for (int v=n;k;v=(lld)v*v%MOD,k>>=1) if (k&1) ret = (lld)ret*v%MOD;
	return ret;
}

inline int inv(int n){ return pow(n, MOD-2); }

int main()
{
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++) A[i][j] = pow(i, j);
		printf("? %d\n", i); fflush(stdout);
		read(A[i][12]);
	}
	for (int i=0;i<N;i++){
		int v = inv(A[i][i]);
		for (int j=0;j<=N;j++) A[i][j] = (lld)A[i][j]*v%MOD;
		for (int k=0;k<N;k++) if (i != k){
			int v = A[k][i];
			for (int j=0;j<=N;j++) A[k][j] = (A[k][j]-(lld)A[i][j]*v+MOD)%MOD;
		}
	}
	for (int i=0;i<MOD;i++){
		int v = 0;
		for (int j=0;j<N;j++) v = (v+(lld)A[j][N]*pow(i, j))%MOD;
		if (v == 0) return printf("! %d\n", i), 0;
	}
	puts("! -1");
}