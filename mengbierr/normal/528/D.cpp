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
struct cp
{
	double x,y;
	cp(double X=0,double Y=0)
	{
		x=X;y=Y;
	}
}a[600005],b[600005],c[600005];
cp operator +(cp a,cp b){return cp(a.x+b.x,a.y+b.y);}
cp operator -(cp a,cp b){return cp(a.x-b.x,a.y-b.y);}
cp operator * (cp a,cp b){return cp(a.x*b.x-a.y*b.y,a.x*b.y+b.x*a.y);}

int n,m,k,L; 
char s[600005],t[600005];
int sum[600005],r[600005];
//const double M_PI=acos(-1.0);
void fft (cp *a,int n,int flag)
{
	for(int i=0;i<n;i++)
	{
		if(r[i]>i) swap(a[i],a[r[i]]);
	}
	for(int i=1;i<n;i<<=1)
	{
		cp w_n(cos(M_PI/i),flag*sin(M_PI/i));
		for(int j=0;j<n;j+=i<<1)
		{
			cp w(1,0);
			for(int k=0;k<i;k++)
			{
				cp x=a[j+k],y=w*a[i+j+k];
				a[j+k]=x+y;a[i+j+k]=x-y;
				w=w*w_n;
			}
		}
	}
}
void solve(char ss,int len)
{
	for(int i=0;i<len;i++) a[i]=b[i]=(cp){0,0};
	for(int i=0;i<n;i++) sum[i+1]=(s[i]==ss);
	for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
	for(int i=0;i<n;i++)
	{
		int L=max(0,i-k),R=min(n-1,i+k)+1;
		if(sum[R]-sum[L]) a[i]=(cp){1,0};
	}
	for(int i=0;i<m;i++)
	{
		if(t[i]==ss) b[i]=(cp){1,0}; 
	}
	fft(a,len,1);fft(b,len,1);
	for(int i=0;i<len;i++)c[i]=c[i]+a[i]*b[i];
}
int main()
{
	n=read();m=read();k=read();
	scanf("%s%s",s,t);
	reverse(t,t+m);
	int lim=1;
	for(lim=1;lim<n+m;lim<<=1)L++;
	for(int i=0;i<=lim;i++)
	r[i]=((r[i>>1]>>1)|(i&1)<<(L-1));
	for(int i=0;i<lim;i++) c[i]=(cp){0,0};
	solve('A',lim);solve('T',lim);solve('C',lim);solve('G',lim);
	fft(c,lim,-1);
	int ans=0;
	for(int i=m-1;i<n;i++)
	{
		c[i].x/=lim;
		//cout<<c[i].x<<" ";
		if((int)(c[i].x+0.1)>=m) ans++;
	}
	cout<<ans;
}