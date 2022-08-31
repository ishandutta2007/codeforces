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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> aa;
		vector<int> bb;
		int ma2=0;
		for(int i=0;i<20;i++){
			if((1<<i)&(n-1)){
				ma2=i;
			}
		}
		for(int i=0;i<n;i++){
			if((i&(1<<ma2))){
				bb.pb(i);
			}
			else{
				aa.pb(i);
			}
		}
		pair<int,int> ma={1e9,-1};
		for(auto j:aa){
			ma=min(ma,{(j^bb[0]),j});
		}
		for(auto j:aa){
			if(j!=ma.b){
				cout<<j<<" ";
			}
		}
		cout<<ma.b<<" ";
		for(auto j:bb){
			cout<<j<<" ";
		}
		cout<<endl;
	}




 
	return 0;
}