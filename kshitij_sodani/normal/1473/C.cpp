//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*for(int i=1;i<=5;i++){
		vector<int> ss;




		for(int j=1;j<=i;j++){
			ss.pb(j);
		}

		for(int j=0;j<4;j++){
			if(next_permutation(ss.begin(),ss.end())){
				continue;
			}
			break;
		}
		int ind=ss.size()-1;
		for(int j=i-1;j>=1;j--){
			ind--;
			ss.pb(ss[ind]);
		}
		int co=0;
		for(auto j:ss){
			cout<<j<<",";
		}
		cout<<endl;
		for(int j=0;j<ss.size();j++){
			for(int k=j+1;k<ss.size();k++){
				if(ss[j]>ss[k]){
					co++;
				}
			}
		}
		cout<<co<<endl;
	}
	return 0;*/
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
	//	int aa=(n-k)*(n-k);
		vector<int> ans;
		for(int i=1;i<k-(n-k);i++){
			ans.pb(i);
		}
		int cur=k;
		while(ans.size()<k){
			ans.pb(cur);
			cur--;
		}
		for(auto j:ans){
			cout<<j<<" ";
		}
		cout<<endl;

		/*for(int i=0;i<n-k+1;i++){
			ans.pb(cur);
			cur--;
		}
		for(auto j:ans){
		}*/

	}

 
 
	
 
	return 0;
}