#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
int A[555];
void rotor(int id)
{
	swap(A[id+1],A[id+2]);
	swap(A[id],A[id+1]);
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		vector<int>ans;
		for(int i=0;i+2<N;i++)
		{
			int mid=i;
			for(int j=i+1;j<N;j++)if(A[mid]>A[j])mid=j;
			while(mid-2>=i)
			{
				ans.push_back(mid-2);
				rotor(mid-2);
				mid-=2;
			}
			if(mid>i)
			{
				ans.push_back(i);
				rotor(i);
				ans.push_back(i);
				rotor(i);
			}
		}
		if(A[N-2]>A[N-1])
		{
			if(A[N-3]==A[N-1])
			{
				ans.push_back(N-3);
				rotor(N-3);
			}
			else
			{
				int fn=-1;
				for(int i=N-4;i>=0;i--)
				{
					if(A[i]==A[i+1])
					{
						fn=i;
						break;
					}
				}
				if(fn<0)
				{
					puts("-1");
					continue;
				}
				if((N-4-fn)%2==0)
				{
					for(int i=N-4;i>=fn;i-=2)
					{
						ans.push_back(i);
						rotor(i);
						ans.push_back(i);
						rotor(i);
						ans.push_back(i+1);
						rotor(i+1);
						ans.push_back(i+1);
						rotor(i+1);
					}
				}
				else
				{
					ans.push_back(N-5);
					rotor(N-5);
					ans.push_back(N-5);
					rotor(N-5);
					ans.push_back(N-3);
					rotor(N-3);
					ans.push_back(N-4);
					rotor(N-4);
					for(int i=N-7;i>=fn;i-=2)
					{
						ans.push_back(i);
						rotor(i);
						ans.push_back(i);
						rotor(i);
						ans.push_back(i+1);
						rotor(i+1);
						ans.push_back(i+1);
						rotor(i+1);
					}
				}
			}
		}
		if(ans.size()>N*N)puts("-1");
		else
		{
			printf("%d\n",(int)ans.size());
			for(int i=0;i<ans.size();i++)
			{
				printf("%d",ans[i]+1);
				if(i+1<ans.size())printf(" ");
			}
			puts("");
		}
	}
}