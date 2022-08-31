#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
 
 
int it[35001];
int dp[35001];
int dp2[35001];
int vis[35001];
int le[35001];
int tree[35001];
int n,k;
void u(int i,int j){
	while(i<=n){
		tree[i]+=j;
		i+=(i&-i);
	}
}
int ss(int i){
	int su=0;
	while(i>0){
		su+=tree[i];
		i-=(i&-i);
	}
	return su;
}
void act(int i,int j){
	u(le[i]+1,j*(i-le[i]));
}
void solve(int l,int r,int aa,int bb){
	//cout<<l<<":"<<r<<":"<<aa<<":"<<bb<<endl;
	//bb+1 to l-1 range should be active
	int mid=(l+r)/2;
	pair<int,int> ma={1e8,-1};
	/*for(int i=l;i<=mid;i++){
 
	}*/
	for(int i=max(bb+1,l);i<=mid;i++){
	//if(i>bb){
			act(i,1);
		//}
	}
	/*for(int i=bb+1;i<=l-1;i++){
		act(i,1);
	}*/
	for(int i=min(mid,bb);i>=aa;i--){
 
		act(i,1);
		int xx=ss(mid+1)-ss(i)+dp[i-1];
		//cout<<i<<":"<<mid<<":"<<xx<<endl;
		ma=min(ma,{xx,i});
		//dp2[mid]=max(dp2[mid],ma);
	}
	/*for(int i=bb+1;i<=l-1;i++){
		act(i,-1);
	}*/
	for(int i=min(mid,bb);i>=aa;i--){
		act(i,-1);
		//int xx=u(mid+1)-u(i);
		//ma=min(ma,{xx,i});
		//dp2[mid]=max(dp2[mid],ma);
	}
	
 
	dp2[mid]=ma.a;
	if(mid<r){
		/*for(int i=max(bb,l);i<=mid;i++){
			if(i>bb){
				act(i,1);
			}
		}*/
		solve(mid+1,r,ma.b,bb);
	/*	for(int i=max(bb,l);i<=mid;i++){
			if(i>bb){
				act(i,-1);
			}
		}*/
	}
	for(int i=max(bb+1,l);i<=mid;i++){
		//if(i>bb){
			act(i,-1);
		//}
	}
	if(mid>l){
		for(int i=ma.b+1;i<=min(bb,l-1);i++){
			act(i,1);
		}
		solve(l,mid-1,aa,ma.b);
		for(int i=ma.b+1;i<=min(bb,l-1);i++){
			act(i,-1);
		}
	}
	
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		vis[i]=-1;
	}
	for(int i=0;i<n;i++){
		cin>>it[i];
		if(vis[it[i]]==-1){
			le[i]=i;
		}
		else{
			le[i]=vis[it[i]];
		}
		vis[it[i]]=i;
	}
 
	for(int i=0;i<n;i++){
		dp[i]=i-le[i];
		if(i>0){
			dp[i]+=dp[i-1];
		}
	}
	//cout<<dp[n-1]<<endl;
	//return 0;
	for(int i=1;i<k;i++){
		solve(i,n-1,i,n-1);
		for(int j=0;j<n;j++){
			dp[j]=dp2[j];
			//cout<<dp[j]<<",";
		}
		//cout<<endl;
 
	}
	cout<<dp[n-1]<<endl;
 
 
 
 
 
 
	return 0;
}