#pragma gcc optimize("O3");
#pragma gcc target("SSE4");
#include <bits/stdc++.h> 
using namespace std;
bool cmp(string h, string k)
{
	return h.size() > k.size();
}
int main()
{
	string w, l;
	int n, t, count = 0;
	cin >> n;
	map <string , vector <string> > E;
	for(int i = 0; i < n; i++)
	{
		cin >> w;
		cin >> t;
		if(E[w].size() == 0)
		{
			count++;
		}
		for(int i = 0; i < t; i++)
		{
			cin >> l;
			E[w].push_back(l);
		}
	}
	cout << count << endl;
	map <string, vector <string> > :: iterator it;
	for(it = E.begin(); it != E.end(); it++)
	{
		cout << it -> first << " ";
		vector <string> Q = it -> second;
		sort(Q.begin(), Q.end(), cmp);
		string k = "";
		map <string, int> R;
		vector <string> J;
		for(int i = 0; i < Q.size(); i++)
		{
			if(R[Q[i]] == 0)
			{
				J.push_back(Q[i]);
				string k = "";
				for(int j = Q[i].size() - 1;j >= 0; j--)
				{
					k.insert(k.begin(), Q[i][j]);
					R[k]++;
				}
			}
		}
		cout << J.size() << " ";
		for(int j = J.size() - 1; j >= 0; j--)
		{
			cout << J[j] << " ";
		}
		cout << endl;
	}
	return 0;
}