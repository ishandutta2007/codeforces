//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


llo n;
llo aa[300001];
llo bb[300001];
llo dp[300001];
llo tree[4*300001];
void update(llo no,llo l,llo r,llo i,llo val){
	if(l==r){
		tree[no]=val;
	}
	else{
		llo mid=(l+r)/2;
		if(i<=mid){
			update(no*2+1,l,mid,i,val);
		}
		else{
			update(no*2+2,mid+1,r,i,val);
		}
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	if(l>bb or r<aa){
		return -1e18;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	else{
		llo mid=(l+r)/2;
		return max(query(no*2+1,l,mid,aa,bb),query(no*2+2,mid+1,r,aa,bb));
	}
}
vector<llo> re[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>aa[i];
	}
	for(llo i=0;i<n;i++){
		cin>>bb[i];
	}
	vector<pair<llo,llo>> ss2;
	for(llo i=n-1;i>=0;i--){
		while(ss2.size()){
			if(ss2.back().a>aa[i]){
				ss2.pop_back();
				continue;;
			}
			break;
		}
		if(ss2.size()){
			re[ss2.back().b].pb(i);
		//	cout<<(ss2.back().b)<<":";
		}
		else{
			//re[n-1].pb(i);
			//cout<<1111<<":";
		}
		ss2.pb({aa[i],i});

	}
	//cout<<endl;
//	return 0;
	for(llo i=0;i<4*n;i++){
		tree[i]=-1e18;
	}
	/*for(int i=0;i<n;i++){
		cout<<re[i]<<",,";
	}
	cout<<endl;*/
	llo mi=n+1;
	vector<pair<llo,llo>> ss;
	multiset<llo> xx;

	for(llo i=0;i<n;i++){
		dp[i]=-1e18;

		if(aa[i]<mi){
			dp[i]=max(dp[i],bb[i]);
			mi=aa[i];
		}
		while(ss.size()){
			if(ss.back().a>aa[i]){
				ss.pop_back();
			}
			else{
				break;
			}
		}
		if(ss.size()){
			llo rr=ss.back().b;
			dp[i]=max(bb[i]+query(0,0,n-1,rr,i-1),dp[i]);
		}
		else{
			if(i>0){
				dp[i]=max(dp[i],bb[i]+query(0,0,n-1,0,i-1));
			}			
		}
		//cout<<i<<":"<<endl;

		ss.pb({aa[i],i});
		if(xx.size()){
			dp[i]=max(dp[i],bb[i]-(*xx.begin()));
		}
		update(0,0,n-1,i,dp[i]);
		for(auto j:re[i]){
			//cout<<i<<",,"<<j<<endl;
			auto jj=xx.find(-dp[j]);
			xx.erase(jj);
		}
		xx.insert(-dp[i]);
	}
/*	for(auto j:xx){
		cout<<j<<"::";
	}
	cout<<endl;*/

	//return 0;
	llo ans=-1e18;
	llo mii=n+1;
	for(llo i=n-1;i>=0;i--){
		if(aa[i]<mii){
			ans=max(ans,dp[i]);
			mii=aa[i];
		}
	}
/*	for(int i=0;i<n;i++){
		cout<<dp[i]<<",";
	}
	cout<<endl;*/
	cout<<ans<<endl;






 
	return 0;
}