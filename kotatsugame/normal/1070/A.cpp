#include<iostream>
#include<queue>
using namespace std;
bool dp[500][5001];
pair<pair<int,int>,int>pr[500][5001];
int d,s;
main()
{
	cin>>d>>s;
	dp[0][0]=true;
	pr[0][0]=make_pair(make_pair(-1,-1),-1);
	queue<pair<int,int> >P;
	P.push(make_pair(0,0));
	while(!P.empty())
	{
		int i=P.front().first,j=P.front().second;
		P.pop();
		for(int k=0;k<10;k++)
		{
			int ni=(i*10+k)%d;
			int nj=j+k;
			if(nj>s)continue;
			if(!dp[ni][nj])
			{
				dp[ni][nj]=true;
				pr[ni][nj]=make_pair(make_pair(i,j),k);
				P.push(make_pair(ni,nj));
			}
		}
	}
	if(!dp[0][s])
	{
		cout<<-1<<endl;
		return 0;
	}
	string ans="";
	int i=0,j=s;
	while(i||j)
	{
		ans+=pr[i][j].second+'0';
		int ni=pr[i][j].first.first;
		int nj=pr[i][j].first.second;
		i=ni,j=nj;
	}
	for(int i=ans.size();i--;)cout<<ans[i];
	cout<<endl;
}