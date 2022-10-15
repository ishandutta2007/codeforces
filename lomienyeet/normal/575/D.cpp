#include <bits/stdc++.h>
using namespace std;
void solve(){
	cout<<"2001\n";
	for(int i=1;i<=1000;i++)cout<<i<<" 1 "<<i<<" 2\n";
	cout<<"1 1 1 2\n";
	for(int i=1;i<=1000;i++)cout<<i<<" 1 "<<i<<" 2\n";
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)solve();
}