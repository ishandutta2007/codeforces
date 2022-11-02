// Problem: AT2369 [AGC013C] Ants on a Circle
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT2369
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2021-11-13 14:11:41
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
#define int long long
const int maxn=3e5+5,M=34005;
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

int n,m,res[maxn],x,y,s,t,b[maxn],id[maxn],f[maxn],ans[maxn];
char ch;
bool cmp(int x,int y){return b[x]<b[y];}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();t=read();
	for(int i=1;i<=n;i++)
	{
		x=read();ch=getchar();b[i]=x;id[i]=i;
		while(ch!='L'&&ch!='R')ch=getchar();
		if(ch=='L')x-=t;
		else x+=t;s=s+x/m;
		if(x<0&&x%m!=0)s--;
		s=s%n+n;s=s%n;
		//cout<<x<<" "<<s<<endl;
		x=x%m;x+=m;x%=m;res[i]=x;
	}
	sort(res+1,res+n+1);
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;i++)f[id[i]]=i;
	//for(int i=1;i<=n;i++)ans[f[i]]=res[i];
	for(int i=1;i<=n;i++)
	{
		if(!res[(f[i]+s-1)%n+1])cout<<m<<" ";
		else cout<<res[(f[i]+s-1)%n+1]<<" ";
	}
 	return 0;
}