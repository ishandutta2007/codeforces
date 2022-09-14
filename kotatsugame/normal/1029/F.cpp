#include<iostream>
#include<vector>
using namespace std;
vector<long long>fac(long long N)
{
	vector<long long>ret;
	for(long long i=1;i*i<=N;i++)if(N%i==0)ret.push_back(i);
	return ret;
}
main()
{
	long long A,B;
	cin>>A>>B;
	vector<long long>a=fac(A),b=fac(B),ab=fac(A+B);
	long long ans=9e18;
	int ai=a.size()-1,bi=b.size()-1;
	for(int i=ab.size();i--;)
	{
		long long h=ab[i];
		long long w=(A+B)/h;
		while(ai>=0&&a[ai]>h)ai--;
		while(bi>=0&&b[bi]>h)bi--;
		if(ai>=0&&A/a[ai]<=w||bi>=0&&B/b[bi]<=w)
		{
			long long now=h+w+h+w;
			if(ans>now)ans=now;
		}
	}
	printf("%lld\n",ans);
}