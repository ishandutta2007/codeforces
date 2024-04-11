#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,x,y,vx,vy,g;
int ans[4][2],ans1=-1;
long long dis[4];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int exgcd(int a,int b,long long &x,long long &y)
{
	int t;
	if(b==0){x=1,y=0;return a;}
	t=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return t;
}
int inv(int a,int b)
{
	long long x,y;
	if(exgcd(a,b,x,y)!=1)return 0;
	x%=b;x+=b;x%=b;
	return x;
}
long long solve(int x,int y)
{
	int d,k;
	long long ans;
	if(vx==1)x=2*n-x;
	if(vy==1)y=2*m-y;
	d=y-x;
	if(d&1)return -1;
	d>>=1;
	d%=m;d+=m;d%=m;
	k=(long long)d*inv(n,m)%m;
	ans=(long long)k*2*n+x;
	return ans;
}
int main()
{
	int dis1=0,dis2=0;
	read(n);read(m);read(x);read(y);read(vx);read(vy);
	if(vx==0)
	{
		if(x==0||x==n)printf("%d %d\n",x,vy==1?m:0);
		else puts("-1");
		return 0;
	}
	if(vy==0)
	{
		if(y==0||y==m)printf("%d %d\n",vx==1?n:0,y);
		else puts("-1");
		return 0;
	}
	ans[0][0]=0;ans[0][1]=0;
	ans[1][0]=0;ans[1][1]=m;
	ans[2][0]=n;ans[2][1]=0;
	ans[3][0]=n;ans[3][1]=m;
	dis1=vx==1?n-x:x;
	dis2=vy==1?m-y:y;
	x+=vx*(dis1<dis2?dis1:dis2);
	y+=vy*(dis1<dis2?dis1:dis2);
	g=gcd(n,g);g=gcd(m,g);g=gcd(x,g);g=gcd(y,g);
	n/=g;m/=g;x/=g;y/=g;
	if(gcd(n,m)!=1)return puts("-1"),0;
	dis[0]=solve(x,y);
	y=m-y;vy=-vy;
	dis[1]=solve(x,y);
	x=n-x;vx=-vx;
	y=m-y;vy=-vy;
	dis[2]=solve(x,y);
	y=m-y;vy=-vy;
	dis[3]=solve(x,y);
	if(dis[0]!=-1&&(!~ans1||dis[0]<dis[ans1]))ans1=0;
	if(dis[1]!=-1&&(!~ans1||dis[1]<dis[ans1]))ans1=1;
	if(dis[2]!=-1&&(!~ans1||dis[2]<dis[ans1]))ans1=2;
	if(dis[3]!=-1&&(!~ans1||dis[3]<dis[ans1]))ans1=3;
	if(ans1==-1)return puts("-1"),0;
	printf("%d %d\n",ans[ans1][0],ans[ans1][1]);
	return 0;
}