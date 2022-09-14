#include<iostream>
using namespace std;
int N,C[20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		int mi=0;
		for(int i=0;i<N;i++)
		{
			cin>>C[i];
			if(C[mi]<C[i])mi=i;
		}
		cout<<mi+1<<"\n";
	}
}