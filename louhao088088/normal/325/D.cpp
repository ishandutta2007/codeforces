#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	char ch=getchar();int x=0;bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=3005*6005;
int n,m,k,f[maxn],a,b,ans=0;
int dx[8]={0,0,1,1,1,-1,-1,-1},dy[8]={1,-1,1,-1,0,1,-1,0};
bool flag[3005][6005];
inline bool check(int &x,int &y)
{
	if(y==0)y=m*2;
	else if(y==m*2+1)y=1;
	if(x>0&&x<=n&&flag[x][y])return true;
	return false;
}
inline int id(int x,int y)
{
	return (x-1)*m*2+y;
}
inline int getf(int x)
{
	if(f[x]==x)return x;
	else return f[x]=getf(f[x]);
}
inline void gett(int x,int y)
{
	x=getf(x),y=getf(y);f[x]=y;
}
inline bool check1(int x,int y)
{
	int x2=x,y2=y+m;
	for(int i=0;i<=7;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(!check(xx,yy))continue;
		for(int j=0;j<8;j++) 
		{
			int xx1=x2+dx[j],yy1=y2+dy[j];
			if(!check(xx1,yy1))continue;
			if(getf(id(xx,yy))==getf(id(xx1,yy1))) {return false;}
		}
	}
	return true;
}
void dele(int x,int y)
{
	int x2=x,y2=y+m;
	for(int i=0;i<=7;i++)
	{
		int xx=x+dx[i],yy=y+dy[i],xx1=x2+dx[i],yy1=y2+dy[i];
		if(check(xx,yy)) gett(id(x,y),id(xx,yy));
		if(check(xx1,yy1))gett(id(x2,y2),id(xx1,yy1));
	}flag[x][y]=1,flag[x2][y2]=1;
}
signed main()
{
	n=read(),m=read(),k=read();
	if(m==1)cout<<"0",exit(0); 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m*2;j++)
			f[id(i,j)]=id(i,j);
	for(int i=1;i<=k;i++)
	{
		a=read(),b=read();
		if(check1(a,b))
		{
			dele(a,b);
			ans++;
		}
	//	for(int i=1;i<=id(n,m*2);i++)cout<<f[i]<<" ";cout<<endl;
	}
	cout<<ans;
	return 0;
}