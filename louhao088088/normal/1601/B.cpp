#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
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
int n,m,f[maxn],g[maxn],a[maxn],b[maxn],tot=0;
queue<int>q;
set<int>s;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	q.push(n);
	for(int i=1;i<n;i++)s.insert(i);
	while(!q.empty())
	{
		int l=q.front();int x=l;//cout<<l<<endl;
		q.pop();l=l+b[l];int r=l-a[l];
		
		if(l>n)continue;
		if(r<=0)
		{
			l=x;//cout<<l<<endl;
			while(l!=n&&l!=0)g[++tot]=l,l=f[l];
			cout<<tot+1<<endl;
			for(int i=tot;i>=1;i--)printf("%d ",g[i]);puts("0");
			exit(0);
		}swap(l,r);
		while(l<=r)
		{
			auto it=s.lower_bound(l);l=*it;if(it==s.end())break;
			if(l>r)break;
			f[l]=x;s.erase(it);q.push(l);
		}
		
	}
	puts("-1");
 	return 0;
}