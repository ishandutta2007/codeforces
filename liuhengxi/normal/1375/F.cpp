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
long long a[3],k=10000000000,d;
int last;
#undef LOCAL
#ifdef LOCAL
void debug()
{fprintf(stderr,"Debug: a = %lld, b = %lld, c = %lld, last = %c\n",a[0],a[1],a[2],last+'a');}
#endif
int main()
{
	read(a[0]);read(a[1]);read(a[2]);
	#ifdef LOCAL
	debug();
	#endif
	puts("First");
	printf("%lld\n",k);fflush(stdout);
	read(last);if(last==0)return 0;a[--last]+=k;
	#ifdef LOCAL
	debug();
	#endif
	printf("%lld\n",k=a[last]*2-a[(last+1)%3]-a[(last+2)%3]);fflush(stdout);
	read(last);if(last==0)return 0;a[--last]+=k;
	#ifdef LOCAL
	debug();
	#endif
	if(a[0]*2==a[1]+a[2])
	{
		d=a[0]>a[1]?a[0]-a[1]:a[1]-a[0];
		printf("%lld\n",k=d);fflush(stdout);
		read(last);if(last==0)return 0;a[--last]+=k;
		#ifdef LOCAL
		debug();
		#endif
		printf("%lld\n",k=5*d);fflush(stdout);
		read(last);if(last==0)return 0;a[--last]+=k;
	}
	else if(a[1]*2==a[0]+a[2])
	{
		d=a[2]>a[1]?a[2]-a[1]:a[1]-a[2];
		printf("%lld\n",k=d);fflush(stdout);
		read(last);if(last==0)return 0;a[--last]+=k;
		#ifdef LOCAL
		debug();
		#endif
		printf("%lld\n",k=5*d);fflush(stdout);
		read(last);if(last==0)return 0;a[--last]+=k;
	}
	else if(a[2]*2==a[0]+a[1])
	{
		d=a[2]>a[1]?a[2]-a[1]:a[1]-a[2];
		printf("%lld\n",k=d);fflush(stdout);
		read(last);if(last==0)return 0;a[--last]+=k;
		#ifdef LOCAL
		debug();
		#endif
		printf("%lld\n",k=5*d);fflush(stdout);
		read(last);if(last==0)return 0;a[--last]+=k;
	}
	else puts("zhimao AK IOI");
	#ifdef LOCAL
	debug();
	#endif
	return 0;
}