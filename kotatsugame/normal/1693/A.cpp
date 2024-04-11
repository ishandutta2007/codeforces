#include<iostream>
using namespace std;
int T,N;
long long A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int r=-1;
		for(int i=0;i<N;i++)
		{
			int a;
			cin>>a;
			if(a!=0)r=i;
			A[i]=a;
		}
		if(r==-1)
		{
			cout<<"Yes\n";
			continue;
		}
		bool ok=true;
		for(int i=r;i>=1;i--)
		{
			long long dec=-A[i];
			if(dec<=0)
			{
				ok=false;
				break;
			}
			A[i-1]-=dec;
		}
		cout<<(ok&&A[0]==0?"Yes\n":"No\n");
	}
}