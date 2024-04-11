#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define MX 128*128
vector<int> v[MX];
int go(string s)
{
	return 128*s[0]+s[1];
}
int deg[MX];
int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		int a=go(s.substr(0,2)),b=go(s.substr(1,2));
		v[a].push_back(b);
		deg[a]++;
		deg[b]--;
	}
	int idx=0;
	for (int i=1;i<MX;i++)
	{
		if (v[idx].empty() || deg[i]>deg[idx])
		idx=i;
	}
	if (count(deg,deg+MX,1)>1 || deg[idx]>1 || *min_element(deg,deg+MX)<-1)
	{
		printf("NO");
		return 0;
	}
	vector<int> ans;
	stack<int> st;
	int cur=idx;
	while (1)
	{
		if (v[cur].empty())
		{
			if (st.empty())
			break;
			ans.push_back(cur);
			cur=st.top();
			st.pop();
		}
		else
		{
			int tmp=v[cur].back();
			v[cur].pop_back();
			st.push(cur);
			cur=tmp;
		}
	}
	if (ans.size()!=n)
	printf("NO");
	else
	{
		printf("YES\n");
		reverse(ans.begin(),ans.end());
		printf("%c%c",idx/128,idx%128);
		for (int i:ans)
		printf("%c",i%128);
	}
}