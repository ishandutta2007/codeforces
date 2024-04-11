#include<bits/stdc++.h>
#define int long long
const int N=105;
using namespace std;

int n,k,mod;

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}
int jc[N],ij[N],iv[N];
int A(int n,int m){
    if(n<m)return 0;
    if(n<N)
		return jc[n]*ij[n-m]%mod;
	int res=1;
	for(int i=n;i>n-m;i--)res=res*i%mod;
	return res;
}
int C(int n,int m){
    return A(n,m)*ij[m]%mod;
}
void init(){
    iv[0]=jc[0]=ij[0]=iv[1]=1;
    for(int i=2;i<N;i++)
        iv[i]=mod-(mod/i)*iv[mod%i]%mod;
    for(int i=1;i<N;i++)
        jc[i]=jc[i-1]*i%mod,ij[i]=ij[i-1]*iv[i]%mod;
}
int xs(int k){return (k&1)?-1:1;}

int dp[N][N],un[N][N]; 
int f[N][N];

void add(int&x,int y){
	x+=y;if(x>=mod)x%=mod;if(x<0)x=x%mod+mod;
} 

void solve(){
	cin>>n>>k>>mod;
	init();
	for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)
			for(int k=0;k<=j;k++){
				add(dp[i][j],C(j,k)*xs(j-k)*gsc(2,i*k));
				add(un[i][j],C(j,k)*xs(j-k)*A(gsc(2,k)-1,i));
			}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)
			for(int x=0;x<i;x++)
				for(int y=0;y<j;y++){
					if(x==n-1&&(n&1))continue;
					add(f[i][j],C(i,x)*C(j,y)%mod*gsc(2,(i-x)*y)%mod*un[i-x][j-y]%mod*(dp[x][y]-f[x][y]));
				}

	int res=0;
	for(int i=0;i<=k;i++)
		add(res,C(k,i)*(dp[n][i]-f[n][i]));
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}