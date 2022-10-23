#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>A,B;
int a[1<<17];
long long f(const vector<int>&a,int sz)
{
	long long ret=0;
	for(int i=0;i<sz;i++)ret+=a[a.size()-1-i];
	return ret;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		A.clear();B.clear();
		for(int i=0;i<N;i++)cin>>a[i];
		long long base=0;
		for(int i=0;i<N;i++)
		{
			int b;cin>>b;
			base+=b;
			if(a[i]==0)A.push_back(b);
			else B.push_back(b);
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		if(A.size()!=B.size())
		{
			int sz=min(A.size(),B.size());
			base+=f(A,sz);
			base+=f(B,sz);
		}
		else
		{
			base+=max(f(A,A.size()-1)+f(B,A.size()),f(A,A.size())+f(B,A.size()-1));
		}
		cout<<base<<"\n";
	}
}