#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,a,b,c,d,e,f;
	cin>>n>>a>>b>>c>>d>>e>>f;
	int x,y;cin>>x>>y;
	auto ile=[&](int k){
		return k<=4||k>=n*3-1;
	};
	int res=0;
	if(ile(a+c+e)&&ile(b+d+f)){
		if(a+c+e<=4&&x==1)res=1;
		if(a+c+e>=n*3-1&&x==n)res=1;
		if(b+d+f<=4&&y==1)res=1;
		if(b+d+f>=n*3-1&&y==n)res=1;
	}else{
		int X=a^c^e,Y=b^d^f;
		if((X-x)%2==0&&(Y-y)%2==0)res=0;
		else res=1;
	}
	cout<<(res?"YES":"NO")<<'\n';
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}