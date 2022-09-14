#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,A,B,C;
string S;
vector<pair<char,int> >X;
vector<int>DO;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>A>>B>>C>>S;
		X.clear();
		for(int i=0;i<N;i++)
		{
			if(!X.empty()&&X.back().first==S[i])X.back().second++;
			else X.push_back(make_pair(S[i],1));
		}
		long long x=0,y=0,z=0;
		for(int i=0;i<X.size();i++)
		{
			if(X[i].first=='1')
			{
				x+=X[i].second-1;
			}
			else
			{
				y+=X[i].second-1;
				if(i>0&&i+1<X.size())z++;
			}
		}
		long long ans;
		if(x==y)
		{
			ans=x*B+y*A;
			if(B>C)ans+=z*(B-C);
		}
		else if(x>y)
		{
			ans=(y+1)*B+y*A;
			x-=y+1;
			if(B>C)
			{
				if(X[0].first=='0'&&x>0)z++,x--;
				if(X.size()>1&&X.back().first=='0'&&x>0)z++,x--;
				ans+=z*(B-C);
			}
		}
		else
		{
			ans=x*B+(x+1)*A;
			if(B>C)
			{
				DO.clear();
				for(int i=1;i+1<X.size();i++)if(X[i].first=='0')
				{
					DO.push_back(X[i].second);
				}
				sort(DO.begin(),DO.end());
				int pd=x;
				z=0;
				for(int d:DO)
				{
					if(pd>=d-1)
					{
						pd-=d-1;
						z++;
					}
				}
				ans=x*B+(x+1)*A+z*(B-C);
			}
		}
		cout<<ans<<"\n";
	}
}