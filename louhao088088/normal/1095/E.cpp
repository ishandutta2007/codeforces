#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=2e6+5;
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
int n,x,cnt,sum[maxn],ans=0;
char s[maxn]; 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),scanf("%s",s);
	for(int i=0;i<n;i++) 
	{
        if(s[i]=='(') cnt++;
        else cnt--;sum[i]=cnt;
    }
     for(int i=n-2;i>=0;--i)
        sum[i]=min(sum[i+1],sum[i]);
    for(int i=0;i<n;i++) 
	{
        if(s[i]=='(') {if(sum[i]>=2&&cnt==2) ans++;x++;} 
		else {if(sum[i]>=-2&&cnt==-2) ans++;x--;}
        if(x<0)break;
    }
    cout<<ans<<endl;
 	return 0;
}