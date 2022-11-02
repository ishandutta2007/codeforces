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

signed main(){
	vpint v;
	rep(i,3){
		int x,y;
		cin>>x>>y;
		v.pb({x,y});
	}
	sort(all(v));
	vpint ans;
	for(int x=v[0].fi;x<=v[1].fi;x++)ans.pb({x,v[0].se});
	for(int x=v[1].fi;x<=v[2].fi;x++)ans.pb({x,v[2].se});
	int mi=min({v[0].se,v[1].se,v[2].se});
	int ma=max({v[0].se,v[1].se,v[2].se});
	for(int y=mi;y<=ma;y++)ans.pb({v[1].fi,y});
	sort(all(ans));
	ans.erase(unique(all(ans)),ans.end());
	cout<<ans.size()<<endl;
	rep(i,ans.size())cout<<ans[i].fi<<" "<<ans[i].se<<endl;
	return 0;
}