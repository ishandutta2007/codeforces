#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

void solve(){
	int N,R;
	scanf("%lld%lld",&N,&R);
	vector<int>X(N);
	rep(i,N)scanf("%lld",&X[i]);
	sort(all(X));
	X.erase(unique(all(X)),X.end());

	int ans=0;
	for(int i=(int)X.size()-1;i>=0;i--){
		if(X[i]<=ans*R)break;
		ans++;
	}
	cout<<ans<<endl;
}

signed main(){
	int Q;scanf("%lld",&Q);
	while(Q--)solve();
	return 0;
}