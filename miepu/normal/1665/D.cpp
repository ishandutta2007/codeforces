#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void ask(int a){
	cout<<"? "<<a<<' '<<(a|(1<<30))<<endl;
}
void ans(int a){
	cout<<"! "<<a<<endl;
}

void solve(){
	int nw=0,mx=1e9;
	for(int i=1;i<=mx;i<<=1){
		ask(i-nw);
		int x;cin>>x;
		if(x!=i)nw|=i;
	}
	ans(nw);
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}