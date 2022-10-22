#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define k1 137
#define k2 233
#define mod1 1000000007
#define mod2 998244353
using namespace std;
char a[255][255];
ll h1[255][255],h2[255][255],b[255],r[1001];int s[255][255][30],t[30];
inline ll get1(int i,int x,int y)
{
	return (h1[i][y]-h1[i][x-1]+mod1)%mod1;
}
inline ll get2(int i,int x,int y)
{
	return (h2[i][y]-h2[i][x-1]+mod2)%mod2;
}
const int MAX=2000;
int len[MAX];
int init(ll *str,int n)
{
    for(int i=1,j=0;i<=2*n;j++,i+=2)
    {
        r[i]=-1;
        r[i+1]=str[j];
    }
    r[0]=-2;
    r[2*n+1]=-1;
    r[2*n+2]=-3;
    r[2*n+3]=-4;
    return 2*n+1;
}
void mana(int n)
{
    int mx=0,p=0,i;
    for (i=1;i<=n;i++)
    {
        if(mx>i)len[i]=min(mx-i,len[2*p-i]);
        else len[i]=1;
        while(r[i-len[i]]==r[i+len[i]])len[i]++;
        if(len[i]+i>mx)mx=len[i]+i,p=i;
    }
}
int main()
{
	int n,m,i,j,k,l,tp,lst,y;ll ans=0;scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) cin>>a[i][j];
	for (i=1;i<=n;i++) for (j=1;j<=m;j++)
	{
		for (k=0;k<26;k++) s[i][j][k]=s[i][j-1][k];
		s[i][j][a[i][j]-'a']++;
		for (k=0;k<26;k++)
		{
			h1[i][j]=h1[i][j]*k1+s[i][j][k]+1;h1[i][j]%=mod1;
			h2[i][j]=h2[i][j]*k2+s[i][j][k]+1;h2[i][j]%=mod2;
		}
	}
	for (i=1;i<=m;i++)
	{
		for (j=i;j<=m;j++)
		{
			lst=1;
			for (k=1;k<=n;k++)
			{
				tp=0;
				for (l=0;l<26;l++) t[l]=s[k][j][l]-s[k][i-1][l],tp+=t[l]%2;
				if (tp>1)
				{
					y=k-lst;
					for (l=lst;l<k;l++)
					{
						b[l-lst]=get1(l,i,j)*(mod1-7)+get2(l,i,j);
					}
					if (y)
					{
						y=init(b,y);
						mana(y);
						for (l=1;l<=y;l++) ans+=len[l]/2;
					}
					lst=k+1;
				}
			}y=k-lst;
			for (l=lst;l<k;l++)
			{
				b[l-lst]=get1(l,i,j)*(mod1-7)+get2(l,i,j);
			}
			if (y)
			{
				y=init(b,y);
				mana(y);
				for (l=1;l<=y;l++) ans+=len[l]/2;
			}
			lst=k+1;
		}
	}
	cout<<ans;
}