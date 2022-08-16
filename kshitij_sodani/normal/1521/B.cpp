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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		pair<llo,llo> mi;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(i==0){
				mi={it[i],i};
			}
			mi=min(mi,{it[i],i});
		}
		cout<<n-1<<endl;
		llo xx=0;
		for(llo i=mi.b-1;i>=0;i--){
			xx^=1;
			cout<<i+1<<" "<<mi.b+1<<" "<<mi.a+xx<<" "<<mi.a<<endl;
		}
		xx=0;
		for(llo i=mi.b+1;i<n;i++){
			xx^=1;
			cout<<i+1<<" "<<mi.b+1<<" "<<mi.a+xx<<" "<<mi.a<<endl;
		}

	}








	return 0;
}