#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,p,s[maxn],t[maxn],w,f[105][maxn],tot=0,g=0,d[maxn],h,o,st[maxn],top;
inline int X(int i){return i;}
inline int Y(int i){return f[o][i]+d[i];}
inline long double slope(int i,int j){return (long double)(Y(j)-Y(i))/(X(j)-X(i));}
signed main()
{
	n=read(),m=read(),p=read();
	for(int i=2;i<=n;i++)s[i]=read(),s[i]+=s[i-1];
	for(int i=1;i<=m;i++)
	{
		w=read(),t[i]=read(),t[i]-=s[w];
	}
	sort(t+1,t+m+1);//cout<<tot<<endl;
	for(int i=1;i<=m;i++)d[i]=d[i-1]+t[i];
	for(int i=1;i<=m;i++)f[1][i]=t[i]*i-d[i];
	for(int i=2;i<=p;i++)
	{
		o=i-1;top=0;st[++top]=i-1;h=1;
		for(int j=i;j<=m;j++)
		{
			int k=t[j];	
			while(h<top&&slope(st[h],st[h+1])<=k)h++;int w=st[h];
			f[i][j]=f[i-1][w]+t[j]*(j-w)-(d[j]-d[w]);
            //cout<<j<<" "<<f[i][j]<<" "<<h<<" "<<top<<endl;
			while(top>h&&slope(st[top-1],st[top])>=slope(st[top-1],j))top--;st[++top]=j;
		}
	}
	cout<<f[p][m]<<endl;
	return 0;
}