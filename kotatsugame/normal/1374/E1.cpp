#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
main()
{
	scanf("%d%d",&N,&K);
	vector<int>A,B,C;
	for(int i=0;i<N;i++)
	{
		int t,a,b;scanf("%d%d%d",&t,&a,&b);
		if(a&&b)C.push_back(t);
		else if(a)A.push_back(t);
		else if(b)B.push_back(t);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	int ans=(int)2e9+1;
	int now=0;
	for(int c:C)now+=c;
	int r=0;
	for(int i=C.size();i>=0;i--)
	{
		while(r<A.size()&&r<B.size()&&i+r<K)
		{
			now+=A[r]+B[r];
			r++;
		}
		if(i+r<K)break;
		if(ans>now)ans=now;
		if(i>0)now-=C[i-1];
	}
	printf("%d\n",ans<=(int)2e9?ans:-1);
}