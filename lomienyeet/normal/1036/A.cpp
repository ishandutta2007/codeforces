#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define multitest int T;cin>>T;while(T--)solve();
void solve(){
	ll N,K;
	cin>>N>>K;
	if(N>=K){
		cout<<"1\n";
		return;
	}
	if(K%N==0){
		cout<<K/N<<"\n";
		return;
	}
	cout<<K/N+1<<"\n";
}
int main(){
	//multitest
	solve();
}