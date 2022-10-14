#include<bits/stdc++.h>
using namespace std;
long long t,n,m;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;)
		cin>>n>>m,cout<<m*(m-1)/2+m*n*(n+1)/2<<"\n";
}