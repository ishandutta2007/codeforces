//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

int t;
bool ask(int i,int j){
	cout<<"1 "<<i<<" "<<j<<endl;
	int x;
	cin>>x;
	return x;
}
bool ask2(int i,vector<int> j){
	cout<<"2 "<<i<<" "<<j.size();
	for(auto jj:j){
		cout<<" "<<jj;;
	}
	cout<<endl;
	int x;
	cin>>x;
	return x;
}
vector<int> solve(int l,int r){
	if(l==r){
		return {l};
	}
	else{
		int mid=(l+r)/2;
		vector<int> aa=solve(l,mid);
		vector<int> bb=solve(mid+1,r);
		vector<vector<int>> cc;
		for(int i=0;i<=bb.size();i++){
			cc.pb({});
		}
		int ind=0;
		for(int i=0;i<aa.size();i++){
			while(ind<bb.size()){
				if(ask(bb[ind],aa[i])){
					ind++;
				}
				else{
					break;
				}
			}
			cc[ind].pb(aa[i]);
		}
		vector<int> dd;
		for(int i=0;i<=bb.size();i++){
			if(i>0){
				dd.pb(bb[i-1]);
			}
			for(auto j:cc[i]){
				dd.pb(j);
			}
		}
		return dd;


	}
}
int ans[501];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> ss=solve(0,n-1);
		/*for(auto j:ss){
			cout<<j<<",";
		}
		cout<<endl;*/
		vector<vector<int>> dd;
		for(int i=0;i<ss.size();i++){
			vector<int> ee;
			ee.pb(ss[i]);
			while(dd.size()){
				vector<int> ff;
				for(auto j:dd){
					for(auto k:j){
						ff.pb(k);
					}
				}
				if(ask2(ss[i],ff)==true){
					for(auto j:dd.back()){
						ee.pb(j);
					}
					dd.pop_back();
				}
				else{
					break;
				}
			}
			dd.pb(ee);
		}
		for(int i=0;i<dd.size();i++){
			for(auto j:dd[i]){
				ans[j]=i;
			}
		}
		cout<<3<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(ans[i]<=ans[j]){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			cout<<endl;
		}
		int yy;
		cin>>yy;
	}




 
 
	return 0;
}