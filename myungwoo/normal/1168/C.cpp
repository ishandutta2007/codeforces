#include <bits/stdc++.h>
using namespace std;

#define pb push_back
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

#define MAXN 300005

int N, Q;
int A[MAXN];
int D[MAXN][19], last[19];

int main()
{
	read(N, Q);
	for (int i=1;i<=N;i++) read(A[i]);
	for (int i=N;i;i--){
		for (int k=19;k--;){
			D[i][k] = 1e9;
			for (int j=19;j--;) if (A[i] & 1<<j && last[j])
				D[i][k] = min(D[i][k], D[last[j]][k]);
		}
		for (int j=19;j--;) if (A[i] & 1<<j) last[j] = D[i][j] = i;
	}
	while (Q--){
		int x, y; read(x, y);
		bool ans = 0;
		for (int i=19;i--;) if (A[y] & 1<<i && D[x][i] <= y) ans = 1;
		puts(ans ? "Shi" : "Fou");
	}
}