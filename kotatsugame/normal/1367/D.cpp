#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T,M,B[50];
main()
{
	cin>>T;
	for(;T--;)
	{
		string s;cin>>s;
		sort(s.begin(),s.end());
		cin>>M;
		for(int i=0;i<M;i++)cin>>B[i];
		string ans(M,'*');
		int ok=0;
		while(ok<M)
		{
			vector<bool>tmp(M,false);
			int nc=0;
			for(int i=0;i<M;i++)if(ans[i]=='*')
			{
				int now=0;
				for(int j=0;j<M;j++)if(ans[j]!='*')now+=abs(i-j);
				if(now==B[i])tmp[i]=true,nc++;
			}
			while(s[s.size()-nc]!=s.back())s.pop_back();
			char c=s.back();
			for(int i=0;i<M;i++)if(tmp[i])
			{
				ans[i]=c;
				ok++;
			}
			while(!s.empty()&&s.back()==c)s.pop_back();
		}
		cout<<ans<<endl;
	}
}