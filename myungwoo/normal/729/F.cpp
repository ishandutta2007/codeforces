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

#define MAXN 4004

int N;
int A[MAXN], S[MAXN];
int D[127][MAXN][127];
bool vis[127][MAXN][127];

int dp(int k, int l, int d)
{
	int &ret = D[k][l][d];
	if (vis[k][l][d]) return ret;
	vis[k][l][d] = 1;
	// d = (N-r)-(l-1)
	int r = N-l+1-d;
	int n = r-l+1;
	if (n < k) return ret = 0;
	ret = -1e9;
	for (int t1=0;t1<2;t1++){
		int take1 = k+t1;
		if (n < take1) continue;
		if (n < take1+take1){ ret = max(ret, S[l+take1-1]-S[l-1]); continue; }
		int mn = 1e9;
		for (int t2=0;t2<2;t2++){
			int take2 = k+t1+t2;
			int value = S[l+take1-1]-S[l-1];
			if (n < take1+take2) continue;
			value -= S[r]-S[r-take2];
			value += dp(take2, l+take1, d+t2);
			mn = min(mn, value);
		}
		ret = max(ret, mn);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	read(N);
	for (int i=1;i<=N;i++) read(A[i]), S[i] = S[i-1]+A[i];
	printf("%d\n", dp(1, 1, 0));
}