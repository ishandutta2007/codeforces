#include<bits/stdc++.h>
using namespace std;
int a,b,n,ans;
int main(){
	cin>>a>>b,n=a+b;
	for(int i=1;i<=n;i=n/(n/i)+1){
		int x=n/i,la=(a+x)/(x+1),lb=(b+x)/(x+1),ra=a/x,rb=b/x;
		if(ra>=la&&rb>=lb)
			ans+=max(0,min(ra+rb,n/x)-max(la+lb,i)+1);
	}
	cout<<ans<<"\n";
}