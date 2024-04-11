#include<iostream>
using namespace std;
int T,K;
int A[1<<17];
bool f(int N,int M)
{
	long long s=0;
	bool n2=false;
	for(int i=0;i<K;i++)
	{
		int now=A[i]/N;
		if(now>=2)
		{
			s+=now;
			if(now>=3)n2=true;
		}
	}
	if(s<M)return false;
	else if(n2)return true;
	else if(s%2!=M%2)return false;
	else return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		int N,M;
		cin>>N>>M>>K;
		for(int i=0;i<K;i++)cin>>A[i];
		cout<<(f(N,M)||f(M,N)?"Yes\n":"No\n");
	}
}