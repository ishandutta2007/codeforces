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
		int n;
		cin>>n;
		map<int,int> ss;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			ss[abs(x)]++;
		}
		int ans=0;
		for(auto j:ss){
			if(j.a==0){
				ans+=1;
				continue;
			}
			ans+=min(j.b,2);
		}
		cout<<ans<<endl;
	}





 
	return 0;
}