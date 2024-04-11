//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		map<int,int> ss;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			ss[it[i]]++;
		}
		int ma=0;
		for(auto j:ss){
			ma=max(ma,j.b);
		}
		cout<<ma<<endl;

	}







 
	return 0;
}