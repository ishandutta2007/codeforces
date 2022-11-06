#include<bits/stdc++.h>
using namespace std;
vector<pair<string, int> > v;
vector<string> G[5000010];
int c, ind;
void f(string s, int x, int cnt)
{
	//cout << c << " " << ind << endl;
	c++;
	if(c == v.size() + 1)
	{
		cout << 1;
		exit(0);
	}
 	G[cnt].push_back(s);
	int i;
	for(i=1; i<=x; i++)
	{
		//ind += 1;
		//if(ind >= v.size()) return;
		f(v[c].first, v[c].second, cnt+1);
	}
}
int main()
{
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	string s;
	cin >> s;
	int i;
	int len = s.size();
	string ss;
	for(i=0; i<len; i++)
	{
		while(s[i] != ',' && i < len)
		{
			ss.push_back(s[i]);
			i++;
		}
		string sss = ss;
		ss.clear();
		i++;
		while(s[i] != ',' && i < len)
		{
			ss.push_back(s[i]);
			i++;
		}
		int j;
		int sum = 0;
		for(j=0; j<ss.size(); j++) sum = 10 * sum + (ss[j] - '0');
		v.push_back(make_pair(sss, sum));
		ss.clear();
	}
	//for(i=0; i<v.size(); i++) cout << v[i].first << " " << v[i].second << endl;
	for(i=0; i<v.size(); i++)
	{
//		cout << "111" << endl;
		ind = i;
		f(v[i].first, v[i].second, 1);
		i = c - 1;
	}
	for(i=1; ; i++)
	{
		if(G[i].size() == 0) break;
	}
	int lll = i - 1;
	cout << lll << endl;
	for(i=1; i<=lll; i++)
	{
		int j;
		for(j=0; j<G[i].size(); j++) cout << G[i][j] << " ";
		cout << endl;
	}
	return  0;
}