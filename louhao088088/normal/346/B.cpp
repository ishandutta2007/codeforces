#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=1e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
string f[105][105][105],a,b,c,ans;
int lena,lenb,lenc,nex[105];
void getMax(string &a,string b)
{
	if(a.size()<b.size())a=b;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>a>>b>>c;
	lena=a.length(),lenb=b.length(),lenc=c.length();
	int j=0;
	for(int i=1;i<lenc;i++)
	{
		while(j>0&&c[i]!=c[j])j=nex[j-1];
		if(c[i]==c[j])j++,nex[i]=j;
	}
	for(int i=1;i<=lena;i++)
	{
		for(int j=1;j<=lenb;j++)
		{
			for(int k=0;k<lenc;k++)
			{
				if(a[i-1]==b[j-1])
				{
					char x=a[i-1];
					int t=k;while(x!=c[t]&&t>0)t=nex[t-1];
					if(x==c[t])t++;
					getMax(f[i][j][t],f[i-1][j-1][k]+x);
				}
				getMax(f[i][j][k],f[i][j-1][k]),getMax(f[i][j][k],f[i-1][j][k]); 
				//cout<<f[i][j][k]<<" "<<i<<" "<<j<<" "<<k<<endl;
			}		
		}
	}
	for(int i=0;i<lenc;i++)getMax(ans,f[lena][lenb][i]);
	if(ans.size()!=0)
	cout<<ans;
	else puts("0");
 	return 0;
}