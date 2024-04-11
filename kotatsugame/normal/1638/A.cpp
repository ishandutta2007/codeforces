#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
int P[500];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>P[i];
		int id=0;
		while(id<N&&P[id]==id+1)id++;
		if(id<N)
		{
			int mi=-1;
			for(int j=id+1;j<N;j++)if(P[j]==id+1)mi=j;
			reverse(P+id,P+mi+1);
		}
		for(int i=0;i<N;i++)cout<<P[i]<<(i+1==N?"\n":" ");
	}
}