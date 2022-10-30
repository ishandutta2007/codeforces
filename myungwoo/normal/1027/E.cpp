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

const int MOD = 998244353;
int N, K;
int D[501][501], E[501][501], C[501];

int main()
{
	read(N, K);
	D[1][1] = 1;
	for (int i=1;i<N;i++){
		for (int j=1;j<=i&&j<K;j++){
			for (int k=1;k<=j;k++) if (D[j][k]){
				if (j == k && j+1 < K) E[j+1][j+1] = (E[j+1][j+1]+D[j][k])%MOD;
				else E[j][k+1] = (E[j][k+1]+D[j][k])%MOD;
				E[j][1] = (E[j][1]+D[j][k])%MOD;
			}
		}
		for (int j=1;j<=i+1&&j<K;j++) for (int k=1;k<=j;k++) D[j][k] = E[j][k], E[j][k] = 0;
	}
	for (int x=1;x<=N&&x<K;x++) for (int i=1;i<=x;i++) C[x] = (C[x]+D[x][i])%MOD;
	int ans = 0;
	for (int x=1;x<=N&&x<K;x++){
		int y = (K-1)/x;
		for (int i=1;i<=N;i++) for (int j=1;j<=i;j++) D[i][j] = 0;
		D[1][1] = C[x];
		for (int i=1;i<N;i++) for (int j=1;j<=i;j++) if (D[i][j]){
			if (j+1 <= y) D[i+1][j+1] = (D[i+1][j+1]+D[i][j])%MOD;
			D[i+1][1] = (D[i+1][1]+D[i][j])%MOD;
		}
		for (int i=1;i<=N;i++) ans = (ans+D[N][i])%MOD;
	}
	write(ans*2%MOD); puts("");
}