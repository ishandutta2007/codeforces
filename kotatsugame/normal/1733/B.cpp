#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,X,Y;
		cin>>N>>X>>Y;
		if(X==0&&Y==0)cout<<"-1\n";
		else if(X>0&&Y>0)cout<<"-1\n";
		else
		{
			int t=X+Y;
			if((N-1)%t!=0)cout<<"-1\n";
			else
			{
				int prv=1;
				int cnt=t;
				for(int i=2;i<=N;i++)
				{
					cnt--;
					cout<<prv<<(i==N?"\n":" ");
					if(cnt==0)cnt=t,prv=i+1;
				}
			}
		}
	}
}