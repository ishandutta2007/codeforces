#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define maxn 262150
#define maxm 105
#define ll long long

int l=-1;
ll N,M,f[maxn][maxm],w[20],sum[10],jc[20];

int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);

	cin>>N>>M;
	for(;N;N/=10) w[++l]=N%10;
	rep(i,0,l){
		sum[w[i]]++;
		if(w[i])
			f[1<<i][w[i]%M]=1;
	}
//	return 0;
	rep(i,1,(1<<l+1)-1){
		rep(k,0,M-1)
		rep(j,0,l){
			if((1<<j^i)>i)
				f[1<<j^i][(k*10+w[j])%M]+=f[i][k];
		}
	}
	ll ans=f[(1<<l+1)-1][0];
	jc[0]=1;
	rep(i,1,l+1)jc[i]=jc[i-1]*i;
	rep(i,0,9) ans/=jc[sum[i]];
	cout<<ans<<endl;
}