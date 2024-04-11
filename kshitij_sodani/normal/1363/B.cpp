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
		cin>>s;
		int ans=s.size();
		if(true){
			int co=0;
			int co2=0;
			for(int i=0;i<s.size();i++){
				if(s[i]=='1'){
					co2++;
				}
			}
			
			ans=min(ans,co2);
			ans=min(ans,(int)s.size()-co2);
			for(int i=0;i<s.size();i++){
				if(s[i]=='0'){
					co++;
				}
				else{
					co2--;
				}
				ans=min(ans,co+co2);
			}
		}
		if(true){
			int co=0;
			int co2=0;
			for(int i=0;i<s.size();i++){
				if(s[i]=='0'){
					co2++;
				}
			}
			
			ans=min(ans,co2);
			ans=min(ans,(int)s.size()-co2);
			for(int i=0;i<s.size();i++){
				if(s[i]=='1'){
					co++;
				}
				else{
					co2--;
				}
				ans=min(ans,co+co2);
			}
		}
		cout<<ans<<endl;
	}



	return 0;
}