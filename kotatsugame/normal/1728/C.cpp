#include<iostream>
#include<queue>
using namespace std;
int f(int N)
{
	int r=0;
	while(N>=1)N/=10,r++;
	return r;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		priority_queue<int>A,B;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;A.push(a);
		}
		for(int i=0;i<N;i++)
		{
			int b;cin>>b;B.push(b);
		}
		int ans=0;
		while(!A.empty())
		{
			int a=A.top();A.pop();
			int b=B.top();B.pop();
			if(a>b)
			{
				ans++;
				A.push(f(a));
				B.push(b);
			}
			else if(a<b)
			{
				ans++;
				A.push(a);
				B.push(f(b));
			}
		}
		cout<<ans<<"\n";
	}
}