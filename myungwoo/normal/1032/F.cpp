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
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define MAXN 300005

const int MOD = 998244353;
int N;
int D[MAXN][3];
vector <int> con[MAXN];

// 0 --- i      
// 1 --- i    , i     
// 2 --- i    , i     

void dp(int n, int p)
{
	D[n][0] = D[n][2] = 1; D[n][1] = 0;
	int m = sz(con[n]);
	if (!m) return;
	vector <int> a1(m), a2(m);
	for (int i=0;i<m;i++){
		int t = con[n][i];
		a1[i] = a2[i] = 1;
		if (t == p) continue;
		dp(t, n);
		a1[i] = a2[i] = (D[t][0]+D[t][1])%MOD;
		D[n][0] = (lld)D[n][0]*D[t][0] % MOD;
	}
	for (int i=1;i<m;i++) a1[i] = (lld)a1[i]*a1[i-1]%MOD;
	for (int i=m-1;i--;) a2[i] = (lld)a2[i]*a2[i+1]%MOD;
	for (int i=0;i<m;i++){
		int t = con[n][i];
		if (t == p) continue;
		D[n][1] = (D[n][1] + (lld)D[t][2] * (i > 0 ? a1[i-1] : 1) % MOD * (i+1 < m ? a2[i+1] : 1)) % MOD;
	}
	D[n][2] = a2[0];
	D[n][0] = (D[n][0]+D[n][1])%MOD;
}

int main()
{
	read(N);
	for (int i=1;i<N;i++){
		int a, b; read(a); read(b);
		con[a].pb(b); con[b].pb(a);
	}
	dp(1, 0);
	printf("%d\n", D[1][0]);
}