#include<bits/stdc++.h>
#define int long long
#pragma comment(linker,"/STACK:128000000,128000000")
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const long long inf2=0x3f3f3f3f3f3f3f3f;
int t;
signed main(){
	cin>>t;
	while(t--){
		int a,b,k;
		cin>>a>>b>>k;
		int cur=(a-b)*(k/2);
		if(k&1)cur+=a;
		cout<<cur<<endl;
	}
	return 0;
}