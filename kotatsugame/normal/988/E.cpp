#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string N;
vector<int>id[10];
int f(int x,int y)
{
	string now=N;
	int ans=0;
	for(int i=y;i+1<N.size();i++)
	{
		swap(now[i],now[i+1]);
		if(i+1==x)x--;
		ans++;
	}
	for(int i=x;i+2<N.size();i++)
	{
		swap(now[i],now[i+1]);
		ans++;
	}
	if(now[0]=='0')
	{
		int id=0;
		while(id+2<now.size()&&now[id]=='0')id++;
		if(id+2==now.size())return(int)1e9;
		ans+=id;
	}
	return ans;
}
main()
{
	cin>>N;
	for(int i=0;i<N.size();i++)id[N[i]-'0'].push_back(i);
	int ans=1e9;
	if(id[0].size()>=2)ans=min(ans,f(id[0][id[0].size()-2],id[0].back()));
	if(id[0].size()&&id[5].size())ans=min(ans,f(id[5].back(),id[0].back()));
	if(id[2].size()&&id[5].size())ans=min(ans,f(id[2].back(),id[5].back()));
	if(id[7].size()&&id[5].size())ans=min(ans,f(id[7].back(),id[5].back()));
	cout<<(ans==(int)1e9?-1:ans)<<endl;
}