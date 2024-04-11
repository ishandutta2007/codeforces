//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int t;
int it[300001];
int co[300001];
int par[300001];
int find(int no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			co[i]=0;
		}
		for(int i=0;i<n;i++){
			cin>>it[i];
			it[i]--;
			co[(-it[i]+i+n)%n]++;
			//
		}
		vector<int> ans;
		for(int i=0;i<n;i++){
			if(co[i]>=n-2*m){//n-2*m){
				for(int j=0;j<n;j++){
					par[j]=j;
				}
				//cout<<i<<endl;
				for(int j=0;j<n;j++){
					int x=find((j-i+n)%n);
					int y=find(it[j]);
					par[x]=y;
				//	cout<<((i+j)%n)<<"::"<<it[j]<<endl;
				}
				int co=0;
				for(int j=0;j<n;j++){
					if(par[j]==j){
						co++;
					}
				}
				int x=n-1-(co-1);
				if(x<=m){
					ans.pb(i);
				}
				//cout<<co<<":";
				//cout<<endl;
			}
		}
	//	cout<<endl;
		cout<<ans.size()<<" ";
		for(auto j:ans){
			cout<<j<<" ";
		}
		cout<<endl;


	}
 
 

 
 
 
	return 0;
}