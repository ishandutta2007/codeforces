#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		string S;cin>>S;
		vector<vector<int> >ids(26);
		for(int i=0;i<S.size();i++)ids[S[i]-'a'].push_back(i);
		int R[26];
		int cnt=0;
		for(int i=0;i<26;i++)
		{
			if(ids[i].empty())R[i]=S.size();
			else
			{
				R[i]=ids[i].back();
				cnt++;
			}
		}
		int usd=0;
		string ans="";
		int pos=0;
		for(;cnt--;)
		{
			int l=pos,r=S.size();
			for(int i=0;i<26;i++)if(!(usd>>i&1))
			{
				r=min(r,R[i]);
			}
			for(int i=26;i--;)if(!(usd>>i&1))
			{
				auto it=lower_bound(ids[i].begin(),ids[i].end(),pos);
				if(it!=ids[i].end()&&*it<=r)
				{
					ans+='a'+i;
					usd|=1<<i;
					pos=*it+1;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
}