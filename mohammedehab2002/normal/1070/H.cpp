#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
string s[10005];
vector<pair<string,int> > all;
int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> s[i];
		set<string> st;
		for (int j=0;j<s[i].size();j++)
		{
			string cur="";
			for (int k=j;k<s[i].size();k++)
			{
				cur+=s[i][k];
				st.insert(cur);
			}
		}
		for (string a:st)
		all.push_back({a,i});
	}
	sort(all.begin(),all.end());
	int q;
	cin >> q;
	while (q--)
	{
		string a;
		cin >> a;
		int cnt=upper_bound(all.begin(),all.end(),make_pair(a,n))-lower_bound(all.begin(),all.end(),make_pair(a,0));
		cout << cnt << ' ';
		if (!cnt)
		cout << "-\n";
		else
		cout << s[(*lower_bound(all.begin(),all.end(),make_pair(a,0))).second] << endl;
	}
}