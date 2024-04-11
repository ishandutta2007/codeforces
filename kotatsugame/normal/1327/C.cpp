#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int N,M,K;
main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<4*K;i++)
	{
		scanf("%*d");
	}
	string ans="";
	for(int i=1;i<N;i++)ans+='U';
	for(int i=1;i<M;i++)ans+='L';
	for(int i=0;i<M;i++)
	{
		if(i%2==0)
		{
			for(int j=1;j<N;j++)ans+='D';
		}
		else
		{
			for(int j=1;j<N;j++)ans+='U';
		}
		if(i+1<M)ans+='R';
	}
	cout<<ans.size()<<endl<<ans<<endl;
}