#include <bits/stdc++.h>

using namespace std;
vector <int> dsu, rang;
int pred(int a)
{
	if(dsu[a] == a) return a;
	else return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
	a = pred(a);
	b = pred(b);
	if(a != b)
	{
		if(rang[a] < rang[b])
		{
			swap(a, b);
		}
		dsu[b] = a;
		if(rang[a] == rang[b])
		{
			rang[a]++;
		}
	}
}
int main() {
	int n;
	cin >> n;
	vector <string> s(n);
	vector <int> cnt(n);
	dsu.resize(n);
	rang.resize(n);
	for(int i = 0; i < n; i++){
		dsu[i] = i;
		rang[i] = 1;
	}
	vector <set <int> > w(26);
	for(int i = 0; i < n; i++){
		cin >> s[i];
		for(int j = 0; j < s[i].size(); j++)
		{
			w[s[i][j] - 'a'].insert(i);
		}
	}
	for(int i = 0; i < 26; i++)
	{
		int pred = -1;
		set <int> :: iterator it;
		for(it = w[i].begin(); it != w[i].end(); it++)
		{
			if(pred != -1)
			{
				unite(pred, *it);
			}
			pred = *it;
		}
	}
	set <int> t;
	for(int i = 0; i < n; i++)
	{
		t.insert(pred(i));
	}
	cout << t.size();
	return 0;
}