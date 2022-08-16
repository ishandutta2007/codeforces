//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
vector<int> ss[100];
int ans=0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.size();
		for(int i=0;i<26;i++){
			ss[i].clear();
		}

		for(int i=0;i<n;i++){
			ss[s[i]-'a'].pb(i);
		}
		ans=0;
		
		for(int i=0;i<26;i++){
			if(ss[i].size()){

				vector<int> ee;
				int co=0;
				int la=-3;
				for(auto j:ss[i]){
					if(j>la+2){
						co++;
						la=j;
					}
				}
				ans+=(ss[i].size()-co);
			}

		}
		cout<<ans<<endl;
	}	



 
	return 0;
}