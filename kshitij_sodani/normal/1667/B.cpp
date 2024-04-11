#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo tree[4*500002][3];
llo pre[500002];
llo it[500002];
llo ind[500002];
llo ind2[500002];
llo dp[500002];
void update(llo no,llo l,llo r,llo i,llo j){
	if(l==r){
		tree[no][0]=j-ind2[i];
		tree[no][1]=j;
		tree[no][2]=j+ind2[i];
	}
	else{
		llo mid=(l+r)/2;
		if(i<=mid){
			update(no*2+1,l,mid,i,j);
		}
		else{
			update(no*2+2,mid+1,r,i,j);
		}
		for(llo j=0;j<3;j++){
			tree[no][j]=max(tree[no*2+1][j],tree[no*2+2][j]);
		}
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb,llo j){
	if(r<aa or l>bb or aa>bb){
		return -(llo)1e18;
	}
	if(aa<=l and r<=bb){
		return tree[no][j];
	}
	llo mid=(l+r)/2;
	return max(query(no*2+1,l,mid,aa,bb,j),query(no*2+2,mid+1,r,aa,bb,j));
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		vector<pair<llo,llo>> ss;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			pre[i+1]=pre[i]+it[i];
		}
		for(llo i=0;i<=n;i++){
			ss.pb({pre[i],i});
		}
		sort(ss.begin(),ss.end());
		for(llo i=0;i<=n;i++){
			ind[ss[i].b]=i;
			ind2[i]=ss[i].b;
		}
		for(llo i=0;i<4*(n+1);i++){
			for(llo j=0;j<3;j++){
				tree[i][j]=-(llo)1e18;
			}
		}
		update(0,0,n,ind[0],0);
		dp[0]=0;
		for(llo i=1;i<=n;i++){
			llo low=-1;
			dp[i]=-(llo)1e18;
			for(llo j=19;j>=0;j--){
				if(low+(1<<j)<=n){
					if(ss[low+(1<<j)].a<pre[i]){
						low+=(1<<j);
					}
				}
			}
			dp[i]=max(dp[i],query(0,0,n,0,low,0)+i);

			llo low2=low;
			for(llo j=19;j>=0;j--){
				if(low+(1<<j)<=n){
					if(ss[low+(1<<j)].a<=pre[i]){
						low+=(1<<j);
					}
				}
			}
			dp[i]=max(dp[i],query(0,0,n,low2+1,low,1));

			low++;

			dp[i]=max(dp[i],query(0,0,n,low,n,2)-i);
			update(0,0,n,ind[i],dp[i]);
		}
		cout<<dp[n]<<endl;

	}







	return 0;
}