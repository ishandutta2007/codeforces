#include<iostream>
using namespace std;
int T,N;
bool usd[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=N;i++)usd[i]=false;
		cout<<"2\n";
		bool fst=true;
		for(int i=1;i<=N;i++)if(!usd[i])
		{
			for(int j=i;j<=N;j*=2)if(!usd[j])
			{
				usd[j]=true;
				if(fst)fst=false;
				else cout<<" ";
				cout<<j;
			}
		}
		cout<<"\n";
	}
}