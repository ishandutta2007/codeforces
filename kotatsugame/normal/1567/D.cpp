#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int T,s,n;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>s>>n;
		priority_queue<int,vector<int>,greater<int> >A;
		{
			int p=1;
			while(s>0)
			{
				for(int i=0;i<s%10;i++)A.push(p);
				s/=10;
				p*=10;
			}
		}
		vector<int>B;
		while(A.size()+B.size()<n)
		{
			while(!A.empty()&&A.top()==1)
			{
				B.push_back(1);
				A.pop();
			}
			int t=A.top();
			A.pop();
			for(int i=0;i<10;i++)A.push(t/10);
		}
		while(B.size()<n-1)
		{
			B.push_back(A.top());
			A.pop();
		}
		int lst=0;
		while(!A.empty())
		{
			lst+=A.top();
			A.pop();
		}
		for(int i=0;i<n-1;i++)cout<<B[i]<<' ';
		cout<<lst<<'\n';
	}
}