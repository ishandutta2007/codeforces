#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	string s;cin>>s;
	int pr=0,ps=4;
	for(auto x:s){
		if(x==pr)ps++;
		else {
			if(ps<2){
				cout<<"No"<<endl;
				return ;
			}
			ps=1;
			pr=x;
		}
	} 
	if(ps<2){
				cout<<"No"<<endl;
				return ;
			}
	cout<<"Yes"<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}