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

int N;
int S[222222],R[222222];

bool ushi(pint a,pint b,pint c){
	return (a.fi*c.fi-b.fi*c.fi)*(a.se*b.se-b.se*c.se)>=(a.se*c.se-b.se*c.se)*(a.fi*b.fi-b.fi*c.fi);
}

signed main(){
	scanf("%lld",&N);
	rep(i,N)scanf("%lld%lld",&S[i],&R[i]);

	vpint v;
	rep(i,N)v.pb(pint(S[i],R[i]));
	sort(all(v));reverse(all(v));
	
	vpint u;
	for(auto p:v){
		if(u.size()&&u.back().se>=p.se)continue;
		u.pb(p);
	}
	reverse(all(u));

	vpint st;
	for(int i=(int)u.size()-1;i>=0;i--){
		while(st.size()>=2&&!ushi(st[st.size()-2],st.back(),u[i]))st.pop_back();
		st.pb(u[i]);
	}

	sort(all(st));
	vint ans;
	rep(i,N){
		if(binary_search(all(st),pint(S[i],R[i])))ans.pb(i);
	}
	rep(i,ans.size()){
		if(i)printf(" ");
		printf("%lld",ans[i]+1);
	}
	puts("");
	return 0;
}