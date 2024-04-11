#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
pair<int,int>p[1<<17];
int ans;
/*long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
struct frac{
	long long A,B;
	frac(long long a,long long b)
	{
		long long g=gcd(a,b);
		a/=g;
		b/=g;
		if(b<0)b=-b,a=-a;
		A=a;
		B=b;
	}
	bool operator<(const frac&rhs)
	{
		return rhs.
	}
};*/
long long B,C,D;
void calc(int i,int j)
{
	long long x1=p[i].first,y1=p[i].second;
	long long x2=p[j].first,y2=p[j].second;
	D=x1-x2;
	B=y1-y2+x2*x2-x1*x1;
	C=(y1-x1*x1)*D-B*x1;
	if(D<0)
	{
		D=-D;
		B=-B;
		C=-C;
	}
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d%d",&p[i].first,&p[i].second);
	sort(p,p+N);
	for(int i=0;i<N;i++)
	{
		while(i+1<N&&p[i].first==p[i+1].first)i++;
		int i2=i+1;
		if(i2==N)break;
		calc(i,i2);
		for(int j=i2+1;j<N;j++)
		{
			long long x=p[j].first,y=p[j].second;
			long long R=D*x*x+B*x+C;
			if(D*y>R)
			{
				i2=j;
				calc(i,i2);
			}
			else if(R>D*1000000)break;
		}
		bool out=false;
		for(int j=i-1;j>=0;j--)
		{
			long long x=p[j].first,y=p[j].second;
			long long R=D*x*x+B*x+C;
			if(D*y>=R)
			{
				out=true;
				break;
			}
			else if(R>D*1000000)break;
		}
		if(!out)ans++;
	}
	printf("%d\n",ans);
}