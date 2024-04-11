
//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo t;

llo it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo ans=0;
		map<llo,llo> ss;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(ss.find(it[i])==ss.end()){
				ss[it[i]]=0;
			}
			ans+=ss[it[i]]*(n-i);;
			ss[it[i]]+=(i+1);
		}
		cout<<ans<<endl;
	}






	return 0;
}