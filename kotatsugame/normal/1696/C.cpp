#include<iostream>
#include<vector>
using namespace std;
int T,N,M,K;
vector<pair<int,long long> >f(int n)
{
	vector<pair<int,long long> >ret;
	for(int i=0;i<n;i++)
	{
		int a;cin>>a;
		long long c=1;
		while(a%M==0)a/=M,c*=M;
		if(ret.empty()||ret.back().first!=a)ret.push_back(make_pair(a,c));
		else ret.back().second+=c;
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		vector<pair<int,long long> >A=f(N);
		int K;cin>>K;
		vector<pair<int,long long> >B=f(K);
		cout<<(A==B?"Yes\n":"No\n");
	}
}