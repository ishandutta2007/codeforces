#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=3e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int T,n,r,ls[5005][5005],f[5005],ans;
char s[5005];
int main() 
{
	T=read();
	while(T--) 
	{
		scanf("%d",&n);scanf("%s",s);
		for(int i=n-1;i>=0;i--) 
			for(int j=i+1;j<n;j++) 
			{
			    if(s[i]<s[j]) ls[i][j]=j;
			    else if(s[i]==s[j]&&j+1<n) ls[i][j]=ls[i+1][j+1];
			    else ls[i][j]=0;			    
			}
		f[0]=ans=n;
		for(int i=1;i<n;i++) 
		{
		    f[i]=n-i;
		    for(int j=i-1;j>=0;j--) 
				if(ls[j][i]) f[i]=max(f[i],f[j]+n-ls[j][i]);
		    ans=max(ans,f[i]);
		}
		printf("%d\n",ans);
	}
	  return 0;
}