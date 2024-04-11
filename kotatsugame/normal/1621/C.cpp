#include<iostream>
using namespace std;
int T,N;
int P[10101];
int ask(int id)
{
	cout<<"? "<<id<<endl;
	int ret;cin>>ret;
	return ret;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=N;i++)P[i]=-1;
		for(int i=1;i<=N;i++)if(P[i]==-1)
		{
			int fst=ask(i);
			int prv=fst;
			while(true)
			{
				int now=ask(i);
				P[prv]=now;
				prv=now;
				if(prv==fst)break;
			}
		}
		cout<<"!";
		for(int i=1;i<=N;i++)cout<<" "<<P[i];
		cout<<endl;
	}
}