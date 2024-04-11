#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
string S;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	vector<int>add;
	for(;T--;)
	{
		cin>>N;
		cin>>S;
		long long ans=0;
		add.clear();
		for(int i=0;i<N;i++)
		{
			int l=i,r=N-i-1;
			int t;
			if(S[i]=='L')ans+=l,t=r-l;
			else ans+=r,t=l-r;
			if(t>0)add.push_back(t);
		}
		sort(add.begin(),add.end());
		reverse(add.begin(),add.end());
		for(int k=1;k<=N;k++)
		{
			if(k<=add.size())ans+=add[k-1];
			cout<<ans<<(k==N?"\n":" ");
		}
	}
}