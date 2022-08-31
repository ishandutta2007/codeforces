//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
 
llo n,q;
llo it[100001];
vector<llo> pre[100001];
vector<llo> pre2[100001];
llo vis[100001];
llo le[100001];
llo re[100001][20];
llo tree[4*100001];
void build(llo no,llo l,llo r){
	if(l==r){
		tree[no]=le[l];
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=min(tree[no*2+1],tree[no*2+2]);
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	if(r<aa or l>bb){
		return n;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	else{
		llo mid=(l+r)/2;
		return min(query(no*2+1,l,mid,aa,bb),query(no*2+2,mid+1,r,aa,bb));
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	for(llo i=2;i<=100000;i++){
		if(vis[i]==0){
			for(llo j=i;j<=100000;j+=i){
				vis[j]=1;
				pre[j].pb(i);
			}
		}
	}
	for(llo i=0;i<n;i++){
		cin>>it[i];
		
	}
	for(llo i=n-1;i>=0;i--){
		llo mi=n;
		for(auto j:pre[it[i]]){
			if(pre2[j].size()){
				mi=min(mi,pre2[j].back());
			}
			//cout<<j<<",";
			pre2[j].pb(i);
		}
		//cout<<endl;
		le[i]=mi;
	}
	build(0,0,n-1);
	llo ind=0;
	for(llo i=0;i<n;i++){
		while(ind<n-1){
			if(query(0,0,n-1,i,ind+1)>ind+1){
				ind++;
				/*if(i==0){
					cout<<ind<<endl;
				}*/
			}
			else{
				break;
			}
		}
		re[i][0]=ind;
		
	}
	//cout<<re[0][0]<<":"<<endl;
	//cout<<re[2][0]<<endl;
	//cout<<query(0,0,n-1,0,1)<<endl;
	for(int j=1;j<20;j++){
		for(int i=0;i<n;i++){
			if(re[i][j-1]==n-1){
				re[i][j]=-1;
			}
			else if(re[i][j-1]==-1){
				re[i][j]=-1;
			}
			else{
				/*if(j==1){
					cout<<j<<":"<<re[i][j]<<endl;
				}*/
				re[i][j]=re[re[i][j-1]+1][j-1];
			}
		}
	}
	/*for(int i=0;i<n;i++){
		cout<<le[i]<<",";
	}
	cout<<endl;*/
	/*for(int i=0;i<n;i++){
		cout<<re[i][0]<<",";
	}
	cout<<endl;*/
//	cout<<re[0][19]<<endl;
	while(q--){
		llo l,r;
		cin>>l>>r;
		l--;
		r--;
		llo ans=0;
		for(llo j=19;j>=0;j--){
			if(l==n){
				break;
			}
			if(re[l][j]==-1){
				continue;
			}
 
			if(re[l][j]<=r){
				l=re[l][j]+1;
				ans+=(1<<j);
			}
		}
		if(l<=r){
			ans+=1;
		}
		cout<<ans<<endl;
 
	}
 
 
 
 
 
 
 
	return 0;
}