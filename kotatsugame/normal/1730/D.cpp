#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		string s,t;
		cin>>N>>s>>t;
		vector<pair<char,char> >U(N);
		for(int i=0;i<N;i++)
		{
			char a=s[i],b=t[N-i-1];
			if(a>b)swap(a,b);
			U[i]=make_pair(a,b);
		}
		sort(U.begin(),U.end());
		int od=0;
		bool out=false;
		for(int i=0;i<N;i++)
		{
			if(i+1<N&&U[i]==U[i+1])i++;
			else if(U[i].first!=U[i].second)out=true;
			else od++;
		}
		cout<<(!out&&N%2>=od?"YES\n":"NO\n");
	}
}