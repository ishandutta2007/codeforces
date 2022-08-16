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
		string s;
		int n;
		cin>>n>>s;
		string ans="";
		string ans2="";
		for(int i=0;i<n;i++){
			if(s[i]=='t'){
				ans2+=s[i];
			}
			else{
				ans+=s[i];
			}
		}
		ans+=ans2;
		cout<<ans<<endl;
	}















 
	return 0;
}