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
struct node{int x,num;}a[maxn];
bool cmp(node a,node b){if(a.num==b.num)return a.x<b.x;return a.num>b.num;}
int n,m,x;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		x=a[i].x=read();
		while(x&&x%3==0)a[i].num++,x=x/3;	
	}sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		print(a[i].x),putchar(' ');
 	return 0;
}