#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,a,b;
int solve(int x,int y){
	return x&&y&&(!solve(y%x,x)||~(y/x%(x+1))&1);
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>a>>b;
		if(a>b)swap(a,b);
		cout<<(solve(a,b)?"First\n":"Second\n");
	}
}