#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
const int LIM=1e9;
vector<int>X;
main()
{
	scanf("%d",&T);
	for(long long a=1;;a+=2)
	{
		long long c=a*a+1;
		c/=2;
		if(c>LIM)break;
		int b=(a*a-1)/2;
		if(a<=b)X.push_back(c);
	}
	sort(X.begin(),X.end());
	for(;T--;)
	{
		scanf("%d",&N);
		printf("%d\n",(int)(upper_bound(X.begin(),X.end(),N)-X.begin()));
	}
}