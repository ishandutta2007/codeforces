#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int N;
int A[2<<17],B[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<N;i++)scanf("%d",&B[i]);
	map<pair<int,int>,int>mp;
	int ans=0,ok=0;
	for(int i=0;i<N;i++)
	{
		int a=A[i],b=B[i];
		if(a==0)
		{
			if(b==0)ok++;
			continue;
		}
		int g=gcd(abs(a),abs(b));
		a/=g;
		b/=g;
		if(a<0)a=-a,b=-b;
		if(a==0&&b<0)b=-b;
		ans=max(ans,++mp[make_pair(a,b)]);
	}
	printf("%d\n",ans+ok);
}