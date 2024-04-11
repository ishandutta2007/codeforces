#include<cstdio>
#include<utility>
#include<map>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,MOD=998244353;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct pow2
{
	int a[N];
	pow2(){F(i,a[0]=1,N)a[i]=(a[i-1]<<1)%MOD;};
	const int &operator[](int x){return a[x];}
}p2;
struct counter
{
	int no[N][2],c[3];
	void init(int n){c[2]=n;}
	void add(int x,int z/*1 or -1*/){c[(no[x][0]==0)+(no[x][1]==0)]+=z;}
	void add(int x,int y/*0 or 1*/,int z/*1 or -1*/){add(x,-1);no[x][y]+=z;add(x,1);}
	int get(){return c[0]?0:p2[c[2]];}
}a0,a1,a2;
int n,m,k;
map<pair<int,int>,int> mat;
int main()
{
	read(n);read(m);read(k);
	a0.init(1);a1.init(n);a2.init(m);
	while(k--)
	{
		int x,y,t;read(x);read(y);read(t);--x,--y;
		if(mat.count(make_pair(x,y)))
		{
			int ori=mat[make_pair(x,y)];
			a0.add(0,(ori^x^y)&1,-1);
			a1.add(x,(ori^y)&1,-1);
			a2.add(y,(ori^x)&1,-1);
			mat.erase(make_pair(x,y));
		}
		if(~t)
		{
			a0.add(0,(t^x^y)&1,1);
			a1.add(x,(t^y)&1,1);
			a2.add(y,(t^x)&1,1);
			mat[make_pair(x,y)]=t;
		}
		printf("%d\n",((a1.get()+a2.get()-a0.get())%MOD+MOD)%MOD);
	}
	return 0;
}