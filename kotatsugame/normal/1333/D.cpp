#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int N,K;
string s;
int now[3030];
main()
{
	cin>>N>>K>>s;
	vector<vector<int> >ids;
	int sum=0;
	vector<int>szs;
	while(true)
	{
		ids.push_back(vector<int>());
		for(int i=0;i+1<s.size();i++)
		{
			if(s[i]=='R'&&s[i+1]=='L')
			{
				ids.back().push_back(i+1);
				s[i]='L';
				s[i+1]='R';
				i++;
			}
		}
		if(ids.back().empty())break;
		sum+=ids.back().size();
		szs.push_back((int)ids.back().size());
	}
	ids.pop_back();
	if(K<ids.size()||sum<K)
	{
		cout<<-1<<endl;
		return 0;
	}
	int id=0,jd=0;
	for(int k=1;k<=K;k++)
	{
		int sz=0;
		now[sz++]=ids[id][jd++];
		sum--;
		while(K-k<sum&&jd<ids[id].size())
		{
			now[sz++]=ids[id][jd++];
			sum--;
		}
		if(jd==ids[id].size())
		{
			id++;
			jd=0;
		}
		printf("%d",sz);
		for(int j=0;j<sz;j++)printf(" %d",now[j]);
		puts("");
	}
}