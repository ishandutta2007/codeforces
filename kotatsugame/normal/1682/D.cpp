#include<iostream>
#include<vector>
using namespace std;
int T,N;
string S;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	vector<int>v;
	vector<pair<int,vector<int> > >cs;
	for(;T--;)
	{
		cin>>N>>S;
		int c1=0;
		for(char c:S)c1+=c=='1';
		if(c1==0||c1%2==1)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		v.clear();
		if(c1==N)
		{
			for(int i=0;i<N;i++)v.push_back(i+1);
		}
		else
		{
			int id=0;
			while(S[id]=='0')id++;
			if(id==0)
			{
				int jd=N;
				while(S[jd-1]=='1')jd--;
				id=jd;
				if(id==N)id=0;
			}
			cs.clear();
			for(int i=0;i<N;i++)
			{
				int j=i+id;
				if(j>=N)j-=N;
				if(cs.empty()||cs.back().first!=S[j]-'0')cs.push_back(make_pair(S[j]-'0',(vector<int>){j+1}));
				else cs.back().second.push_back(j+1);
			}
			for(int i=0;i<cs.size();i+=2)
			{
				for(int j=0;j+1<cs[i].second.size();j++)v.push_back(cs[i].second[j]);
				cout<<cs[i].second.back()<<" "<<cs[i+1].second[0]<<"\n";
				for(int j=0;j+1<cs[i+1].second.size();j++)
					cout<<cs[i+1].second[j]<<" "<<cs[i+1].second[j+1]<<"\n";
				v.push_back(cs[i+1].second.back());
			}
		}
		for(int i=0;i+1<v.size();i++)cout<<v[i]<<" "<<v.back()<<"\n";
	}
}