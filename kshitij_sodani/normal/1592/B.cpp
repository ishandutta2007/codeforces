//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[100001];
llo tt[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,x;
		cin>>n>>x;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			tt[i]=it[i];
		}
		vector<llo> aa;
		vector<llo> bb;
		for(llo i=0;i<n;i++){
			if((abs(i-0))>=x or abs(i-(n-1))>=x){
				aa.pb(it[i]);
				bb.pb(i);
			}
			else{

			}
		}
		sort(aa.begin(),aa.end());
		for(llo i=0;i<bb.size();i++){
			tt[bb[i]]=aa[i];
		}
		string ans="YES";
		sort(it,it+n);
		for(llo i=0;i<n;i++){
			if(it[i]!=tt[i]){
				ans="NO";
			}
		}
		cout<<ans<<endl;

	}



 
 
 
	return 0;
}