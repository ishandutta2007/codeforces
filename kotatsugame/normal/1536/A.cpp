#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<int>A(N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		sort(A.begin(),A.end());
		while(A.size()<=300)
		{
			vector<int>B;
			for(int i=0;i<A.size();i++)
			{
				for(int j=i+1;j<A.size();j++)B.push_back(A[j]-A[i]);
			}
			sort(B.begin(),B.end());
			B.erase(unique(B.begin(),B.end()),B.end());
			int sz=A.size();
			vector<int>nA;
			int ai=0,bi=0;
			while(ai<A.size()||bi<B.size())
			{
				if(ai==A.size())nA.push_back(B[bi++]);
				else if(bi==B.size())nA.push_back(A[ai++]);
				else if(A[ai]==B[bi])nA.push_back(A[ai++]),bi++;
				else if(A[ai]<B[bi])nA.push_back(A[ai++]);
				else nA.push_back(B[bi++]);
			}
			A=nA;
			if(sz==A.size())break;
		}
		if(A.size()>300)puts("NO");
		else
		{
			puts("YES");
			printf("%d\n",A.size());
			for(int i=0;i<A.size();i++)printf("%d%c",A[i],i+1==A.size()?10:32);
		}
	}
}