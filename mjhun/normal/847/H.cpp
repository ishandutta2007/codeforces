#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

const int MXN=1e5+3;
ll N, A[MXN];
ll cnt[2][MXN], val[2][MXN];

int main(){
	cin >> N;
	fore(x,1,N+1)cin>>A[x];

	fore(x,1,N+1){
		val[0][x]=max(val[0][x-1]+1,A[x]);
		cnt[0][x]=cnt[0][x-1]+(val[0][x]-A[x]);
	}

	for(int x=N; x>=1; x--){
		val[1][x]=max(val[1][x+1]+1, A[x]);
		cnt[1][x]=cnt[1][x+1]+(val[1][x]-A[x]);
	}

	ll ans=1LL<<61;

	fore(x,0,N+1)
		ans=min(ans, cnt[0][x] + cnt[1][x+1] + max(val[1][x+1]+1-val[0][x],0LL));

	cout << ans << "\n";
	return 0;
}