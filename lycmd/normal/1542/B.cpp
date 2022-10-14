#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a,b;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>a>>b;
		int flg=a==1&&(n-1)%b==0;
		for(int i=1;a>1&&i<=n;i*=a)
			flg|=(n-i)%b==0;
		cout<<(flg?"Yes\n":"No\n");
	}
}//