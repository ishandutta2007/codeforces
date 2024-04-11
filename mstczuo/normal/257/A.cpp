# include <iostream>
# include <vector>
# include <cstdio>
# include <algorithm>

using namespace std;

int n,m,k,x,ans;
vector<int> E;
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x>1)
			E.push_back(x-1);
	}
	sort(E.begin(),E.end());
	m-=k;
	while(m>0&&!E.empty())
	{
		m-=E.back();
		E.pop_back();
		ans++;
	}
	if(m>0&&E.empty())
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
}