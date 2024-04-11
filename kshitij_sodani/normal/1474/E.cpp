//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo t;
llo it[100001];
llo aa[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo ans2=0;
		for(llo i=1;i<n;i++){
			ans2+=(max(i,n-1-i)*max(i,n-1-i));
		}
		vector<pair<int,int>> ans;
		for(llo i=1;i<n-1;i++){
			if(i>n-1-i){
				ans.pb({i+1,1});
			}
		}
		for(llo i=1;i<n-1;i++){
			if(i<=n-1-i){
				ans.pb({i+1,n});
			}
		}
		ans.pb({1,n});
		for(int i=1;i<=n;i++){
			aa[i]=i;
		}
		for(int i=ans.size()-1;i>=0;i--){
			swap(aa[ans[i].a],aa[ans[i].b]);
		}

		cout<<ans2<<endl;
		for(int i=1;i<=n;i++){
			cout<<aa[i]<<" ";
		}
		cout<<endl;
		cout<<ans.size()<<endl;
		for(auto j:ans){
			cout<<j.a<<" "<<j.b<<endl;
		}
	}





	
 
	return 0;
}