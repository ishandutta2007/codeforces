//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[50];
llo tt[50];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		string s;
		cin>>s;
		for(llo i=0;i<n;i++){
			it[i]=s[i]-'0';
			tt[i]=it[i];
		}
		llo ans=0;
		sort(tt,tt+n);
		for(llo i=0;i<n;i++){
			if(it[i]!=tt[i]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
 
 

 
 
 
	return 0;
}