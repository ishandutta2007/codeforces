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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string t;
		cin>>t;
		string ans="";
		vector<int> qq;
		for(int i=0;i<26;i++){
			qq.pb(i);
		}
		int st=1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='a'){
				st=0;
			}
		}
		if(t=="abc" and st==0){
			swap(qq[1],qq[2]);
		}

		for(auto j:qq){
			for(int i=0;i<s.size();i++){
				if((s[i]-'a')==j){
					ans.pb(s[i]);
				}
			}
		}
		cout<<ans<<endl;


		

	}





 
	return 0;
}