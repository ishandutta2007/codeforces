#include<iostream>
using namespace std;
int T,N;
int S[1<<17];
int P[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>S[i];
		bool ok=true;
		for(int i=0;i<N;)
		{
			int j=i;
			while(j<N&&S[j]==S[i])j++;
			if(i+1==j)
			{
				ok=false;
				break;
			}
			for(int k=i;k<j;k++)P[k]=k+1;
			P[j-1]=i;
			i=j;
		}
		if(ok)
		{
			for(int i=0;i<N;i++)cout<<P[i]+1<<(i+1==N?"\n":" ");
		}
		else cout<<"-1\n";
	}
}