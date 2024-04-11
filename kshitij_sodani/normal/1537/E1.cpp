//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int n,k;
string s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	cin>>s;

	/*for(int i=0;i<n;i++){
		cin>>s[i];
	}*/
	string ans="";
	for(int i=0;i<k;i++){
		ans+=s[0];
	}
	for(int i=0;i<n;i++){
		if(i+1<=k){
			string ans2="";
			for(int j=0;j<k;j++){
				ans2+=s[j%(i+1)];
			}
			if(ans2<ans){
				ans=ans2;
			}
		}
	}
	cout<<ans<<endl;




	return 0;
}