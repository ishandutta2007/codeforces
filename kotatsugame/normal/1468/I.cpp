#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
long long a,b,c,d;
main()
{
	scanf("%d%lld%lld%lld%lld",&N,&a,&b,&c,&d);
	while(c!=0)
	{
		if(a<0){a=-a;b=-b;}
		if(c<0){c=-c;d=-d;}
		long long t=a/c;
		a-=t*c;
		b-=t*d;
		swap(a,c);
		swap(b,d);
	}
	if(d==0)
	{
		puts("NO");
		return 0;
	}
	if(d<0)d=-d;
	b=(b%d+d)%d;
	vector<pair<int,int> >ans;
	for(int x=0;x<a;x++)
	{
		long long ly=(b*x+a-1)/a;
		long long ry=ly+d;
		for(long long y=ly;y<ry;y++)
		{
			ans.push_back(make_pair(x,y));
			if(ans.size()>N)break;
		}
		if(ans.size()>N)break;
	}
	if(ans.size()!=N)puts("NO");
	else
	{
		puts("YES");
		for(pair<int,int>p:ans)printf("%d %d\n",p.first,p.second);
	}
}