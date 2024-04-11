#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
ll ans=0;
int n,tim;
char s[1000005];
struct SAM
{
	int last,cnt,a[2000005][26],tot;
	int fa[2000005],mx[2000005],val[2000005];
	int v[2000005],q[2000005];
	int vis[2000005];
	SAM()
	{
		last=++cnt;
	}
	void insert(int c)
	{
		int p=last,np=last=++cnt;
		mx[np]=mx[p]+1;val[np]=1;
		while(!a[p][c]&&p) a[p][c]=np,p=fa[p];
		if(!p) fa[np]=1;
		else
		{
			int q=a[p][c];
			if(mx[q]==mx[p]+1) fa[np]=q;
			else
			{
				int nq=++cnt;
				mx[nq]=mx[p]+1;
				fa[nq]=fa[q];
				fa[np]=fa[q]=nq;
				memcpy(a[nq],a[q],sizeof(a[q]));
				while(a[p][c]==q) a[p][c]=nq,p=fa[p];
			}
		}
	}
	void pre()
	{
		/*for(int i=1;i<=cnt;i++)
		{
			for(int j=0;j<=3;j++)
			cout<<a[i][j]<<' ';
			cout<<endl;
		}//*/
		for(int i=1;i<=cnt;i++) v[mx[i]]++;
		for(int i=1;i<=n;i++) v[i]+=v[i-1];
		for(int i=cnt;i;i--) q[v[mx[i]]--]=i;
		for(int i=cnt;i;i--) val[fa[q[i]]]+=val[q[i]];
	}
	int p,l;
	void solve(int c)
	{
		while(!a[p][c]&&p)
		{
			p=fa[p];
			l=mx[p];
		}
		if(a[p][c]) p=a[p][c],l++;
		//cout<<l<<" ";
		if(vis[p]!=tim&&l>=n) vis[p]=tim,ans+=val[p];
		if(n!=1)
		if(mx[fa[p]]+1>=n) p=fa[p],l=mx[p];
	}
}sam;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		sam.insert(s[i]-'a');
	}
	sam.pre();
	int q=read();
	for(tim=1;tim<=q;tim++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		sam.p=1;sam.l=0;
		ans=0;
		for(int i=n+1;i<2*n;i++)
		s[i]=s[i-n];
		for(int i=1;i<2*n;i++)
		sam.solve(s[i]-'a');
		printf("%d\n",ans);
	}
}
/*
aaaaaaaaaa
5
aaaa
22
aaaaa
20
aaaaaa
15
aaa
21
a
10
*/