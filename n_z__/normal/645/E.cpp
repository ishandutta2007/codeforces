#include<bits/stdc++.h>
using namespace std;
#define int long long
bool vis[101];
const int p=1e9+7;
int dp[2000001];
int lst[101];
int k;
vector<int>aa,bb;
const int Maxn=105;
int a[Maxn<<1],b[Maxn<<1],c[Maxn<<1],h[Maxn],tp[Maxn<<1],lim;
void mul(int *A,int *B){
	for(int i=0;i<=lim;i++)
	tp[i]=0;
	for(int i=0;i<=k;i++)
	for(int j=0;j<=k;j++)
	tp[i+j]=(tp[i+j]+A[i]*B[j])%p;
	for(int i=lim;i>=k;i--){
		for(int j=0;j<k;j++)
			tp[i-k+j]=(tp[i-k+j]+tp[i]*a[k-j])%p;
		tp[i]=0;
	}
	for(int i=0;i<=lim;i++)A[i]=tp[i];
}
void power(int *A,int B,int *C){
	for(;B;B>>=1,mul(A,A))if(B&1)mul(C,A);
}
int calc(int q)
{
	if(q<aa.size())return dp[q];
	k++;
	int nn=q-aa.size()+k;
	lim=k<<1;
	for(int i=1;i<=k;i++)a[i]=0;
	a[1]=2,a[k]=-1;
	for(int i=1;i<=k;i++)h[i]=dp[aa.size()-(k+1)+i];
	if(nn<k)return h[nn+1];
	b[0]=1;
	c[1]=1;
	int ans=0;
	power(c,nn,b);
	for(int i=0;i<k;i++)
	(ans+=b[i]*h[i+1]%p)%=p;
	return ans;
	//return dp[q]=(2*calc(q-1)-calc(q-k-1))%p;
}
main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>m>>k;
    string s;
    cin>>s;
	m=s.size()+m;
    n=s.size();
    s=' '+s;
	aa.push_back(0);
	for(int x=1;x<=n;x++)
	{
		char y=s[x];
		aa.push_back(y-'a'+1);
		vis[y-'a'+1]=1;
	}
	for(int x=1;x<=k;x++)
	if(!vis[x])aa.push_back(x),n++;
	memset(vis,0,sizeof(vis));
	for(int x=n;x>=1;x--)
	if(!vis[aa[x]])bb.push_back(aa[x]),vis[aa[x]]=1;
	for(int x=bb.size()-1;x>=0;x--)
	aa.push_back(bb[x]);
	for(int x=1;x<aa.size();x++)
	{
		if(lst[aa[x]]==0)dp[x]=(2*dp[x-1]+1)%p;
		else dp[x]=(2*dp[x-1]-dp[lst[aa[x]]-1])%p;
		lst[aa[x]]=x;
	}
	cout<<(calc(m)+p+1)%p<<endl;
}