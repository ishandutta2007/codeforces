//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,p,q,L[4004][4004],R[4004][4004];
int cost[4004],hp[4004],t[4004];
pair<int,pair<int,int> >P[4004];
inline void upd(int &x,int y){
	if(y>x)x=y;
}
void calc_ans(){
	t[0]=-inf;t[n+1]=inf;
	for(int i=1;i<=n;i++){
		if(t[i]/p!=t[i-1]/p){
			for(int j=0;j<=4000;j++){
				L[i][j]=(cost[i]<=j?hp[i]:0);
			}
		}else{
			for(int j=0;j<=4000;j++)L[i][j]=L[i-1][j];
			for(int j=0;j+cost[i]<=4000;j++){
				upd(L[i][j+cost[i]],L[i-1][j]+hp[i]);
			}
		}
	}
	for(int i=n;i>=1;i--){
		if(t[i]/p!=t[i+1]/p){
			for(int j=0;j<=4000;j++){
				R[i][j]=(cost[i]<=j?hp[i]:0);
			}
		}else{
			for(int j=0;j<=4000;j++)R[i][j]=R[i+1][j];
			for(int j=0;j+cost[i]<=4000;j++){
				upd(R[i][j+cost[i]],R[i+1][j]+hp[i]);
			}
		}
	}
}
void query(int time,int money){
	int l=-1,r=-1;
	for(int i=n;i>=1;i--){
		if(t[i]/p==time/p&&t[i]<=time){
			r=i;break;
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i]/p==time/p-1&&t[i]+p-1>=time){
			l=i;break;
		}
	}
	int ans=0;
	for(int i=0;i<=money;i++){
//		cerr<<l<<" "<<r<<" "<<(l==-1?0:R[l][i])<<" "<<(r==-1?0:L[r][money-i])<<endl;
		ans=max(ans,(l==-1?0:R[l][i])+(r==-1?0:L[r][money-i]));
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>P[i].second.first>>P[i].second.second>>P[i].first;
	}
	sort(P+1,P+n+1);
	for(int i=1;i<=n;i++){
		t[i]=P[i].first;
		cost[i]=P[i].second.first;
		hp[i]=P[i].second.second;
	}
	calc_ans();
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		query(a,b);
	}
	return 0;
}