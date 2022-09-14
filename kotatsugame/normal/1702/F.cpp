#include<iostream>
#include<queue>
using namespace std;
int T,N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		priority_queue<int>A,B;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;A.push(a);
		}
		for(int i=0;i<N;i++)
		{
			int b;cin>>b;B.push(b);
		}
		bool ok=true;
		while(!A.empty())
		{
			int a=A.top();
			int b=B.top();
			if(a==b)
			{
				A.pop();
				B.pop();
			}
			else if(a>b)
			{
				if(a%2==1)
				{
					ok=false;
					break;
				}
				A.pop();
				A.push(a/2);
			}
			else
			{
				B.pop();
				B.push(b/2);
			}
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}