//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		set<llo> ss;
		for(llo i=1;i<n;i++){
			for(llo j=0;j<i;j++){
				ss.insert(it[i]-it[j]);
			}
		}
		cout<<ss.size()<<endl;
	}




 
	return 0;
}