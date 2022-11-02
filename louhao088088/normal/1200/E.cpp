#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
const int maxn=1e6+5,mod=1e9+7,mod2=998244353;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
void print(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m,sum[maxn],len,d=0,sum2[maxn],base[maxn],base2[maxn];
char s[maxn],g[maxn];
int getnum(char a)
{
	if(a>='0'&&a<='9')return a-'0';
	if(a>='A'&&a<='Z')return 10+a-'A';
	else return 37+a-'a';
}
bool check(int l,int r,int x,int y)
{
//	cout<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
	if(r-l!=y-x)return 0;//if(y>n||r>n)return 0;
	int s=(sum[r]-sum[l-1]*base[r-l+1]%mod+mod)%mod,s2=(sum[y]-sum[x-1]*base[y-x+1]%mod+mod)%mod;
//	cout<<s<<" "<<s2<<endl; 
	if(s!=s2)return 0;
	s=(sum2[r]-sum2[l-1]*base2[r-l+1]%mod2+mod2)%mod2,s2=(sum2[y]-sum2[x-1]*base2[y-x+1]%mod2+mod2)%mod2;
	if(s!=s2)return 0;
	return 1;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();base[0]=base2[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);len=strlen(s+1);
		for(int j=1;j<=len;j++)
		{
			sum[d+j]=sum[d+j-1]*97+getnum(s[j]);sum[d+j]%=mod;
			sum2[d+j]=sum2[d+j-1]*113+getnum(s[j]);sum2[d+j]%=mod2;
			base[d+j]=base[d+j-1]*97%mod;base[d+j]%=mod;
			base2[d+j]=base2[d+j-1]*113%mod2;base2[d+j]%=mod2;
		}int x=1;
		for(int j=max(1ll,d-len+1);j<=d;j++)
			if(check(j,d,d+1,d+d-j+1))
			{
				x=d-j+2;break;
			}
		for(int j=x;j<=len;j++)
		{
			d++;sum[d]=sum[d-1]*97+getnum(s[j]);sum[d]%=mod;g[d]=s[j];
			sum2[d]=sum2[d-1]*113+getnum(s[j]);sum2[d]%=mod2;
		}
	}
	for(int i=1;i<=d;i++)putchar(g[i]);
 	return 0;
}