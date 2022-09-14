#include<iostream>
using namespace std;
int A[2<<17];
bool ex[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=1;i<=N;i++)ex[i]=false;
		int id=N-1;
		while(id>=0&&!ex[A[id]])
		{
			ex[A[id]]=true;
			id--;
		}
		cout<<id+1<<"\n";
	}
}