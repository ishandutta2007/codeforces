#include<bits/stdc++.h>
using namespace std;
int n,a1,a2,a3,b1,b2,b3;
signed main(){
	cin>>n>>a1>>a2>>a3>>b1>>b2>>b3;
	cout<<n-min(a1,n-b2)-min(a2,n-b3)-min(a3,n-b1)<<" "
	    <<min(a1,b2)+min(a2,b3)+min(a3,b1);
}