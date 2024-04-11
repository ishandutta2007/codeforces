#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
const int maxn=2e5+5;
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
int n,m,f[maxn],T,len,id,sum,ans;
char c[maxn]; 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		scanf("%s",c+1);len=strlen(c+1);ans=0;id=0;sum=0;
		for(int i=1;i<=len;i++)
		{
			if(c[i]=='?')f[i]=f[i-1]+1;
			else
			{
				if((!((i-id)%2)&&sum==c[i]-'0')||((i-id)%2&&sum!=c[i]-'0')||!id)f[i]=f[i-1]+1;
                else f[i]=i-id;id=i,sum=c[i]-'0';
			}ans+=f[i];
			//cout<<ans<<endl;
		}
		print(ans);puts("");
		
	}
 	return 0;
}