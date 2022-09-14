#include<cstdio>
#include<vector>
using namespace std;
int N;
long long A[2<<17];
long long S[2<<17];
long long dfs(int L,int R,int k)
{
	if(L==R||k<0)return 0;
	vector<int>d;
	long long ret=0;
	for(int i=L;i<R;i++)if(A[i]>>k&1)
	{
		if(!d.empty())
		{
			int j=d.back();
			if(i-j>=2&&(A[i]^A[j])==S[i]-S[j+1])ret--;
		}
		d.push_back(i);
	}
	for(int i=0;i<d.size();i++)
	{
		int l=i<=1?L-1:d[i-2];
		int r=i+2<d.size()?d[i+2]:R;
		int m=d[i];
		for(int k=m-2;k>l;k--)if((A[m]^A[k])==S[m]-S[k+1])ret++;
		for(int k=m+2;k<r;k++)if((A[m]^A[k])==S[k]-S[m+1])ret++;
		l=i==0?L:d[i-1]+1;
		ret+=dfs(l,m,k-1);
	}
	if(d.empty())ret+=dfs(L,R,k-1);
	else ret+=dfs(d.back()+1,R,k-1);
	return ret;
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%lld",&A[i]);
		S[i+1]=S[i]+A[i];
	}
	printf("%lld\n",dfs(0,N,29));
}