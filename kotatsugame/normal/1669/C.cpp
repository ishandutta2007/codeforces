#include<iostream>
using namespace std;
int T,N;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int e[2]={-1,-1};
		bool f=false;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			if(e[i%2]==-1)e[i%2]=a%2;
			else if(e[i%2]!=a%2)f=true;
		}
		cout<<(f?"NO\n":"YES\n");
	}
}