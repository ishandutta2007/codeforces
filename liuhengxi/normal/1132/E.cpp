#include<cstdio>
#include<bitset>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1700,n=840,m=840*2*36;
template<typename T>T& read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
	return x;
}
long long w,tot,ans;
long long cnt[10];
bitset<36*N> f;
int main()
{
	read(w);
	f[0]=1;
	F(i,1,9)
	{
		int k=1;
		read(cnt[i]);
		if(cnt[i]>n-i)tot+=(cnt[i]/(n/i)-1)*n,cnt[i]-=(cnt[i]/(n/i)-1)*(n/i);
		while(k<=cnt[i])k=k<<1|1;
		k>>=1;
		cnt[i]-=k;
		f|=f<<(cnt[i]*i);
		for(int d=1;d&k;d<<=1)f|=f<<(d*i);
	}
	F(i,0,min((long long)m,w+1))if(f[i])ans=max(ans,min(tot,(w-i)/n*n)+i);
	printf("%lld\n",ans);
	return 0;
}