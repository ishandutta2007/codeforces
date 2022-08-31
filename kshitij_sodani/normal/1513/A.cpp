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

	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int le=n/2;
		if(n%2==0){
			le--;
		}
		if(le<k){
			cout<<-1<<endl;
			continue;
		}
		vector<int> ans;
		for(int i=0;i<n;i++){
			ans.pb(0);
		}
		int ind=1;
		int cur=n;

		for(int i=0;i<k;i++){
			ans[ind]=cur;
			cur--;
			ind+=2;
		}
		cur=1;
		for(int i=0;i<n;i++){
			if(ans[i]==0){
				ans[i]=cur;
				cur++;
			}
		}
		for(auto j:ans){
			cout<<j<<" ";
		}
		cout<<endl;

	}


 
 
	return 0;
}