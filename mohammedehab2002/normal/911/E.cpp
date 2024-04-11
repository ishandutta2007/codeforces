#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;
stack<int> st;
set<int> s;
vector<int> ans;
int main()
{
	int n,k,nex=1;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	s.insert(i);
	for (int i=0;i<k;i++)
	{
		int a;
		scanf("%d",&a);
		ans.push_back(a);
		s.erase(a);
		st.push(a);
		while (st.top()==nex)
		{
			st.pop();
			nex++;
			if (st.empty())
			break;
		}
	}
	while (!st.empty())
	{
		set<int>::iterator it=s.upper_bound(st.top());
		st.pop();
		if (it==s.begin())
		continue;
		vector<int> tmp;
		it--;
		while (it!=s.begin())
		{
			tmp.push_back(*it);
			it--;
		}
		tmp.push_back(*it);
		for (int i=0;i<tmp.size();i++)
		{
			ans.push_back(tmp[i]);
			s.erase(tmp[i]);
		}
	}
	vector<int> tmp;
	for (set<int>::iterator it=s.begin();it!=s.end();it++)
	tmp.push_back(*it);
	for (int i=tmp.size()-1;i>=0;i--)
	ans.push_back(tmp[i]);
	stack<int> ok;
	nex=1;
	for (int i=0;i<n;i++)
	{
		ok.push(ans[i]);
		while (ok.top()==nex)
		{
			ok.pop();
			nex++;
			if (ok.empty())
			break;
		}
	}
	if (!ok.empty())
	{
		printf("-1");
		return 0;
	}
	for (int i=0;i<n;i++)
	printf("%d ",ans[i]);
}