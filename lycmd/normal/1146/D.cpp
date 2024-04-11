#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,a,b,ans;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>m>>a>>b,ans=m+1;
	for(int x=a,y=a;x>0;y=max(y,x))
		ans+=(y<=m)*(m-y+1),x+=x<b?a:-b;
	if(m>=a+b){
		int g=gcd(a,b);
		ans+=(m-a-b+1+m%g+1)*((m-a-b)/g+1)/2;
	}
	cout<<ans<<"\n";
}//