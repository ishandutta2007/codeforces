#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int t,N,K;
char S[2020];
char T[2020];
main()
{
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d%d\n%s",&N,&K,S);
		for(int i=0;i<K-1;i++)
		{
			T[2*i]='(';
			T[2*i+1]=')';
		}
		for(int i=(K-1)*2;i<N;i++)
		{
			T[i]=i-(K-1)*2<=N/2-K?'(':')';
		}
		T[N]=0;
		vector<pair<int,int> >ans;
		for(int i=0;i<N;i++)if(T[i]!=S[i])
		{
			int j=i+1;
			while(T[i]!=S[j])j++;
			ans.push_back(make_pair(i+1,j+1));
			reverse(S+i,S+j+1);
		}
		printf("%d\n",(int)ans.size());
		for(pair<int,int>p:ans)printf("%d %d\n",p.first,p.second);
	}
}