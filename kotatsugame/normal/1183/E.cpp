#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,K,ans;
string s;
main()
{
	cin>>N>>K>>s;
	K--;
	vector<string>S;
	S.push_back(s);
	int id=1;
	while(K>0)
	{
		vector<string>T;
		for(string s:S)
		{
			for(int i=1;i<=s.size();i++)
			{
				T.push_back(s.substr(0,i-1)+(i<s.size()?s.substr(i):""));
			}
		}
		sort(T.begin(),T.end());
		T.erase(unique(T.begin(),T.end()),T.end());
		int ret=min(K,(int)T.size());
		ans+=id*ret;
		id++;
		K-=ret;
		if(id>N)break;
		S=T;
	}
	cout<<(K>0?-1:ans)<<endl;
}