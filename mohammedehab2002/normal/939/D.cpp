#include <iostream>
#include <vector>
using namespace std;
int par[26];
int find(int x)
{
	if (par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x!=y)
	par[x]=y;
}
vector<pair<char,char> > ans;
int main()
{
	int n;
	string a,b;
	cin >> n >> a >> b;
	for (int i=0;i<26;i++)
	par[i]=i;
	for (int i=0;i<n;i++)
	Union(a[i]-'a',b[i]-'a');
	for (int i=0;i<26;i++)
	{
		if (find(i)!=i)
		ans.push_back({find(i)+'a',i+'a'});
	}
	cout << ans.size() << endl;
	for (int i=0;i<ans.size();i++)
	cout << ans[i].first << ' ' << ans[i].second << endl;
}