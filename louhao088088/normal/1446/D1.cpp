#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=400005;
int n,m,a[maxn],s[maxn],M=0,k=0,p,l[maxn*2],ans=0,g[maxn];
void solve(int x)
{
	memset(l,0,sizeof l);int h=0,F=0;
	for(int i=1;i<=n;i++)if(a[i]==x)s[i]=-1;
	//for(int i=1;i<=n;i++)cout<<s[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)
	{
		h=h+s[i];
		if(!l[h+200000]&&h!=0)l[h+200000]=i,F=1;
		else if(!F)continue;
		else if(h==0)ans=max(ans,i);
		else ans=max(ans,i-l[200000+h]);
	}for(int i=1;i<=n;i++)if(a[i]==x)s[i]=0;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),g[a[i]]++;M=max(M,g[a[i]]);
	}
	for(int i=1;i<=100;i++)if(M==g[i])k++,p=i;
	if(k>=2)printf("%d\n",n),exit(0);
	else
	{
		for(int i=1;i<=n;i++)if(a[i]==p)s[i]=1;//cout<<"A";
		for(int i=1;i<=100;i++)if(i!=p)solve(i);
		cout<<ans<<endl;
	}
	return 0;
}