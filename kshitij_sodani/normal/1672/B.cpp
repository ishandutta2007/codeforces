#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.size();
		if(s[n-1]=='A'){
			cout<<"NO"<<endl;
			continue;
		}
		int co=0;
		string ans="YES";
		for(int i=0;i<s.size();i++){
			if(s[i]=='A'){
				co++;
			}
			else{
				co--;
			}
			if(co<0){
				ans="NO";
			}
		}
		cout<<ans<<endl;
		

	}









	return 0;
}