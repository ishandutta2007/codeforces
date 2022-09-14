#include<iostream>
using namespace std;
int T,N,K;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K>>S;
		int cnt=0;
		int id=0;
		while(S[id]!='*')id++;
		while(id<N)
		{
			cnt++;
			int pre=N;
			for(int k=0;k<K;k++)
			{
				if(id+1+k<N&&S[id+1+k]=='*')pre=id+1+k;
			}
			id=pre;
		}
		cout<<cnt<<endl;
	}
}