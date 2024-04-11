#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,R;
main()
{
	scanf("%d%d",&N,&R);
	vector<pair<int,int> >A,B;
	for(int i=0;i<N;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(b>=0)A.push_back(make_pair(a,b));
		else B.push_back(make_pair(a,b));
	}
	sort(A.begin(),A.end());
	for(pair<int,int>a:A)
	{
		if(R<a.first)
		{
			puts("NO");
			return 0;
		}
		R+=a.second;
	}
	sort(B.begin(),B.end(),[](pair<int,int>a,pair<int,int>b)
	{
		return a.first+a.second>b.first+b.second;
	});
	for(pair<int,int>b:B)
	{
		if(R<b.first)
		{
			puts("NO");
			return 0;
		}
		R+=b.second;
	}
	puts(R<0?"NO":"YES");
}