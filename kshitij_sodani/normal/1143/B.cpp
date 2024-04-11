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
	int n;
	cin>>n;
	vector<int> ss;
	while(n){
		ss.pb(n%10);
		n/=10;
	}
	reverse(ss.begin(),ss.end());
	llo ans=1;
	for(auto j:ss){
		ans*=j;
	}
	for(int i=0;i<ss.size();i++){
		llo ans2=1;
		for(int j=0;j<ss.size();j++){
			if(j<i){
				ans2*=ss[j];
			}
			else if(j==i){
				if(i==0 and ss[j]==1){
					continue;
				}
				if(ss[j]==0){
					ans2=0;
					continue;
				}
				ans2*=(ss[j]-1);
			}
			else{
				ans2*=9;
			}
		}
		ans=max(ans,ans2);
	}
	cout<<ans<<endl;

	



 
	return 0;
}