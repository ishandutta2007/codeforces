#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();int x=0;bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
#define int long long
const int mod=1e9+7,mod2=998244353,maxn=1e6+5;
int n,m,sum[maxn],sum2[maxn],base[maxn],base2[maxn],g[maxn];
char a[maxn];
bool check(int l,int r,int x,int y)
{
//	cout<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
	if(r-l!=y-x)return 0;if(y>n||r>n)return 0;
	int s=(sum[r]-sum[l-1]*base[r-l+1]%mod+mod)%mod,s2=(sum[y]-sum[x-1]*base[y-x+1]%mod+mod)%mod;
	//cout<<s<<" "<<s2<<endl;
	if(s!=s2)return 0;
	s=(sum2[r]-sum2[l-1]*base2[r-l+1]%mod2+mod2)%mod2,s2=(sum2[y]-sum2[x-1]*base2[y-x+1]%mod2+mod2)%mod2;
	if(s!=s2)return 0;
	return 1;
}
int lcs(int x,int y)
{
	int l=0,r=n,res=-1;
	//cout<<x<<" "<<y<<endl;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(x,x+mid,y,y+mid))res=mid,l=mid+1;
		else r=mid-1;
	}
	return res;
}
signed main()
{
	n=read(),m=read();
	scanf("%s",a+1);base[0]=1;base2[0]=1;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]*29+a[i]-'a';sum[i]%=mod;
		sum2[i]=sum2[i-1]*39+a[i]-'a';sum2[i]%=mod2;
		base[i]=base[i-1]*29%mod;base2[i]=base2[i-1]*39%mod2;
	}
	for(int i=1;i<=n;i++)
	{
		if(n/i<m)break;int F=0;
		for(int j=2;j<=m;j++)
		{
			if(!check(1,i,(j-1)*i+1,j*i))
			{
				F=1;break;
			}
		}//cout<<i<<" "<<F<<endl;
		if(!F)
		{
			int s=min(i,lcs(1,m*i+1)+1);//cout<<s<<endl;
			g[m*i]++,g[m*i+s+1]--;
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		g[i]+=g[i-1];
		if(g[i]>0)putchar('1');
		else putchar('0');
	}	
	return 0;
}