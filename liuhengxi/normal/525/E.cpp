#include<cstdio>
#include<unordered_map>
#include<chrono>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=26;
const long long fac[19]={1,1,2,6,24,120,720,5040,40320,362880,3628800,
39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,
355687428096000,6402373705728000};
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct node
{
	int a[28],b[3];
	node()
	{
		a[0]=a[1]=a[2]=a[3]=a[4]=a[5]=a[6]=a[7]=a[8]=a[9]=a[10]=a[11]=a[12]=
		a[13]=a[14]=a[15]=a[16]=a[17]=a[18]=a[19]=a[20]=a[21]=a[22]=a[23]=
		a[24]=a[25]=a[26]=a[27]=0;
		b[0]=b[1]=b[2]=0;
	}
	void add(int x)
	{
		++a[x];
		if(x<14){if(x<7)++b[0];else ++b[1];}
		else if(x<21)++b[2];
	}
	int query(int x)
	{
		int ans=0;
		while(x%7)ans+=a[--x];
		if(x>=7)ans+=b[0],x-=7;
		if(x>=7)ans+=b[1],x-=7;
		if(x>=7)ans+=b[2],x-=7;
		return ans;
	}
};
long long T=chrono::steady_clock::now().time_since_epoch().count()/1000*1001;
struct myhash{int operator()(long long x)const{return (x^T)%153427;}};
int n,k,a[N],mid;
long long s,ans;
unordered_map<long long,node,myhash> m;
void dfs1(int pos,int exc,long long sum)
{
	if(exc>k)return;
	if(sum>s)return;
	if(pos==mid)return void(m[s-sum].add(exc));
	dfs1(pos+1,exc,sum);
	dfs1(pos+1,exc,sum+a[pos]);
	if(a[pos]>18)return;
	dfs1(pos+1,exc+1,sum+fac[a[pos]]);
}
void dfs2(int pos,int exc,long long sum)
{
	if(exc>k)return;
	if(sum>s)return;
	if(pos==mid)return void(ans+=m[sum].query(k-exc+1));
	--pos;
	dfs2(pos,exc,sum);
	dfs2(pos,exc,sum+a[pos]);
	if(a[pos]>18)return;
	dfs2(pos,exc+1,sum+fac[a[pos]]);
}
int main()
{
	read(n);read(k);read(s);
	F(i,0,n)read(a[i]);
	mid=n/2;
	dfs1(0,0,0);
	dfs2(n,0,0);
	printf("%lld\n",ans);
	return 0;
}