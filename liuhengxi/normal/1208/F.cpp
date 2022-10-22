#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,M=1<<21;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],f[M],ans;
void add(int now,int cnt)
{
	if(f[now]==2)return;
	if(cnt==21)
	{
		if(f[now]<2)++f[now];
		return;
	}
	if(!(now>>cnt&1))return add(now,cnt+1);
	add(now^(1<<cnt),cnt+1);
	add(now,cnt+1);
}
int query(int x,int ban,int bit=1<<20)
{
	if(!bit)return x;
	if(!(ban&bit)&&f[x|bit]==2)return query(x|bit,ban,bit>>1);
	return query(x,ban,bit>>1);
}
int main()
{
	read(n);
	F(i,0,n)read(a[n-1-i]);
	add(a[0],0);add(a[1],0);
	F(i,2,n)
	{
		int tmp=a[i]|query(0,a[i]);
		if(tmp>ans)ans=tmp;
		add(a[i],0);
	}
	printf("%d\n",ans);
	return 0;
}