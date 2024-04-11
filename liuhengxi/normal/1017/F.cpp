#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e8+50;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct
{
	const int pos[30]={-1,0,-1,-1,-1,-1,-1,1,-1,-1,-1,2,-1,3,-1,-1,-1,4,-1,5,-1,-1,-1,6,-1,-1,-1,-1,-1,7};
	bool a[30];
	unsigned char c[N/30];
	void set(int x){if(x<30)return a[x]=1,void();int y=x/30;x-=y*30;if(~pos[x])c[y]|=1<<pos[x];}
	bool operator[](int x){if(x<30)return a[x];int y=x/30;x-=y*30;return !~pos[x]||(c[y]>>pos[x]&1);}
}vis;
int n;
unsigned a,b,c,d,ans;
void calc(int p)
{
	unsigned f=((a*p+b)*p+c)*p+d,cnt=0;
	for(int i=n/p;i;i/=p)cnt+=i;
	ans+=f*cnt;
}
int main()
{
	read(n,a,b,c,d);
	F(i,2,n+1)
	{
		if(!vis[i])
		{
			calc(i);
			if((long long)i*i<=n)for(int j=i*i;j<=n;j+=i)vis.set(j);
		}
	}
	printf("%u\n",ans);
	return 0;
}