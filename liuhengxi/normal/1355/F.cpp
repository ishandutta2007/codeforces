#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const vector<int> qy[16]={{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,},{53,59,61,67,71,73,79,83,89,},{97,101,103,107,109,113,127,131,},{137,139,149,151,157,163,167,173,},{179,181,191,193,197,199,211,},{223,227,229,233,239,241,251,},{257,263,269,271,277,281,283,},{293,307,311,313,317,331,337,},{347,349,353,359,367,373,379,},{383,389,397,401,409,419,},{421,431,433,439,443,449,},{457,461,463,467,479,487,},{491,499,503,509,521,523,},{541,547,557,563,569,571,},{577,587,593,599,601,607,},{613,617,619,}};
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
int tt;
long long gcd(long long a,long long b){return !b?a:gcd(b,a%b);}
long long lcm(long long a,long long b){return a/gcd(a,b)*b;}
int query(long long x)
{
	printf("? %lld\n",x);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	#ifdef LOCAL
	ans=(int)(gcd(ans,x));
	#endif
	return ans;
}
int main()
{
	read(tt);
	while(tt--)
	{
		vector<int> fac;
		int ans=1;
		F(i,0,16)
		{
			long long prod=1;
			for(int x:qy[i])prod*=x;
			int g=query(prod);
			for(int x:qy[i])if(g%x==0)fac.emplace_back(x);
		}
		F(i,0,(int)fac.size()>>1)
		{
			int p=fac[i<<1],q=fac[i<<1|1],a=0,b=0;
			long long x=1,y=1;
			while(x*p<=1000000000)x*=p;
			while(y*q<=1000000000)y*=q;
			long long g=query(x*y);
			while(g%p==0)g/=p,++a;
			while(g%q==0)g/=q,++b;
			ans=ans*(a+1)*(b+1);
		}
		if(fac.size()&1)
		{
			int p=fac[fac.size()-1],a=0;
			long long x=1;
			while(x*p<=1000000000)x*=p;
			long long g=query(x);
			while(g%p==0)g/=p,++a;
			ans=ans*(a+1);
		}
		if(ans<7)ans+=7;
		else ans<<=1;
		printf("! %d\n",ans);
		fflush(stdout);
	}
	return 0;
}