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
	int A,B,N;
	scanf("%lld%lld%lld",&A,&B,&N);
	while(N--){
		int l,t,m;
		scanf("%lld%lld%lld",&l,&t,&m);
		int lb=l-1,ub=1001001001;
		while(ub-lb>1){
			int mid=(ub+lb)/2;
			bool ok=true;
			if(A+(mid-1)*B>t)ok=false;
			else if((A+(l-1)*B+A+(mid-1)*B)*(mid-l+1)/2>m*t)ok=false;
			if(ok)lb=mid;
			else ub=mid;
		}
		if(ub==l)cout<<-1<<endl;
		else cout<<lb<<endl;
	}
	return 0;
}