#include<bits/stdc++.h>
#define int long long
#define w1(c,d,f,g) if(s=='G'||s==c)ans+=d*(m-f),g=max(g,d*(m-f)),d=1,f=m
using namespace std;
signed main(){
	int n;
	cin>>n;
	int ans=0;
	bool R=0,G=0,B=0;
	int c=0,v=0,d=0,f=0,g=0;
	for(int x=1;x<=n;x++){
		int m;
		char s;
		cin>>m>>s;
		w1('R',R,d,c);
		w1('B',B,f,v);
		if(s=='G')ans+=G*min(0ll,m-g-c-v),g=m,G=1,c=v=0;
	}
	cout<<ans;
}