#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=405,mod=1e9+7;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int f[maxn][maxn],n;
int getf(int x,int k)
{
	if(!k)return 1;
	if(x==1)return k==1?1:0;
	if(f[x][k]!=-1)return f[x][k];f[x][k]=0;
	for(int i=0;i<k;i++)f[x][k]=(f[x][k]+getf(x-1,i)*getf(x-1,k-i-1))%mod;
	for(int i=0;i<=k;i++)f[x][k]=(f[x][k]+getf(x-1,i)*getf(x-1,k-i))%mod;
	for(int i=0;i<=k;i++)f[x][k]=(f[x][k]+getf(x-1,i)*getf(x-1,k-i)%mod*2*k)%mod;
	for(int i=0;i<=k+1;i++)f[x][k]=(f[x][k]+getf(x-1,i)*getf(x-1,k-i+1)%mod*(k+1)*k)%mod;
	return f[x][k]%mod;
}
signed main()
{
	n=read();memset(f,-1,sizeof f);
	cout<<getf(n,1);
	return 0;
}