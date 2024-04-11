#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
int Ask(int x,int y)
{
	printf("SCAN %d %d\n",x,y);fflush(stdout);
	return read();
}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),m=read();
		int s1=Ask(1,1),s2=Ask(n,1);
		int sx=(s1-s2+2*n+2);
		sx>>=1;
		int sy=s1+4-sx;
		int px=sx>>1,py=sy>>1;
		int s3=Ask(px,1),s4=Ask(1,py);
		int dx=s3+2-sy,  dy=s4+2-sx;
		int x1=(sx-dx)>>1,x2=(sx+dx)>>1;
		int y1=(sy-dy)>>1,y2=(sy+dy)>>1;
		printf("DIG %d %d\n",x1,y1);fflush(stdout);
		int f=read();
		if(f==1)
		{
			printf("DIG %d %d\n",x2,y2);fflush(stdout);
			read();
		}
		else
		{
			printf("DIG %d %d\n",x1,y2);fflush(stdout);
			read();
			printf("DIG %d %d\n",x2,y1);fflush(stdout);
			read();
		}
	}
	return 0;
}