#include <iostream>
#include <string.h>
#include <map>
#include <set>
using namespace std;
set<string> st;
map<string,int> m[55];
string arr[55];
int main()
{
	int n;
	cin >> n;
	for (int x=0;x<n;x++)
	{
		string s;
		cin >> s;
		arr[x]=s;
		for (int i=0;i<s.size();i++)
		{
			if (!m[x][s])
			m[x][s]=i+1;
			st.insert(s);
			char c=s[0];
			s=s.substr(1,s.size());
			s+=c;
		}
	}
	int ans=(1<<30);
	for (set<string>::iterator it=st.begin();it!=st.end();it++)
	{
		string uni=*it;
		bool b=1;
		int cur=0;
		for (int i=0;i<n;i++)
		{
			if (!m[i][uni])
			b=0;
			cur+=m[i][uni]-1;
		}
		if (b)
		ans=min(ans,cur);
	}
	if (ans==(1<<30))
	ans=-1;
	cout << ans;
}