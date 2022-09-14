#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int N,Z,X[2<<17];
main()
{
	scanf("%d%d",&N,&Z);
	for(int i=0;i<N;i++)scanf("%d",&X[i]);
	sort(X,X+N);
	int L=0,R=N/2+1;
	while(R-L>1)
	{
		int M=(L+R)/2;
		if(M*2>N)
		{
			R=M;
			continue;
		}
		bool flag=1;
		for(int i=0;i<M;i++)
		{
			flag&=X[N-M+i]-X[i]>=Z;
		}
		if(flag)L=M;
		else R=M;
	}
	cout<<L<<endl;
}