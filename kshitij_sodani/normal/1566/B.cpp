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

	llo t;
	cin>>t;
	while(t--){	
		string s;
		cin>>s;
		int ans=0;
		int st=-1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){

				st=-1;
			}
			else{
				if(st==-1){
					ans++;
					st=1;
				}
			}
		}
		ans=min(ans,2);
		cout<<ans<<endl;



	}


 
 
 
	return 0;
}