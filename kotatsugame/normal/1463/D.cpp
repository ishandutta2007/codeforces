#include<cstdio>
#include<vector>
using namespace std;
int T,N;
int B[2<<17];
bool ex[4<<17];
int L[2<<17],R[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=1;i<=2*N;i++)ex[i]=false;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&B[i]);
			ex[B[i]]=true;
		}
		vector<int>A;
		for(int i=1;i<=2*N;i++)if(!ex[i])A.push_back(i);
		for(int i=0;i<N;i++)
		{
			if(i>0)L[i]=L[i-1]+1;
			else L[i]=0;
			if(L[i]>N)L[i]=N;
			while(L[i]<N&&A[L[i]]<=B[i])L[i]++;
		}
		for(int i=N;i--;)
		{
			if(i<N-1)R[i]=R[i+1]-1;
			else R[i]=N-1;
			if(R[i]<0)R[i]=-1;
			while(R[i]>=0&&A[R[i]]>=B[i])R[i]--;
		}
		int cnt=0;
		for(int x=0;x<=N;x++)
		{
			if(x>0&&L[x-1]==N)continue;
			if(x<N&&R[x]==-1)continue;
			cnt++;
		}
		printf("%d\n",cnt);
	}
}