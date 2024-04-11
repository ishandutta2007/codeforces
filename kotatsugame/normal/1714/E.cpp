#include<iostream>
#include<algorithm>
using namespace std;
int A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		cin>>N;
		bool f0=false,f2=false;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			if(A[i]%10==5)A[i]+=5;
			else if(A[i]%10!=0)
			{
				while(A[i]%10!=2)A[i]+=A[i]%10;
			}
			if(A[i]%10==0)f0=true;
			else f2=true;
		}
		sort(A,A+N);
		if(f0&&f2)
		{
			cout<<"No\n";
			continue;
		}
		else if(f0)
		{
			cout<<(A[0]==A[N-1]?"Yes\n":"No\n");
			continue;
		}
		int ev=0;
		for(int i=0;i<N;i++)ev|=1<<A[i]/10%2;
		if(ev==3)cout<<"No\n";
		else cout<<"Yes\n";
	}
}