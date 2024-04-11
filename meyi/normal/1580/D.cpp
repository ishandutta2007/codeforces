#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=4010;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int a[maxn],m,n;
vector<ll>solve(int l,int r){
	vector<ll>ret(r-l+2,LLONG_MIN);
	ret[0]=0;
	if(l>r)return ret;
	ri pos=min_element(a+l,a+r+1)-a;
	vector<ll>ansL=solve(l,pos-1),ansR=solve(pos+1,r);
	for(ri i=0;i<ansL.size();++i)
		for(ri j=0;j<ansR.size();++j){
			ckmax(ret[i+j],ansL[i]+ansR[j]-2ll*i*j*a[pos]);
			ckmax(ret[i+j+1],ansL[i]+ansR[j]-(2ll*(i+1)*(j+1)-1)*a[pos]+1ll*m*a[pos]);
		}
	return ret;
}
signed main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	printf("%lld",solve(1,n)[m]);
	return 0;
}