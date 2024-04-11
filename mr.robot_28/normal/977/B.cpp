#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
	int n;
	string a;
	cin >> n >> a;
	map<string , int> Q;
	vector <pair <int, string > > W;
	for(int i = 0; i < n - 1; i++)
	{
		string h;
		h.append(a, i, 2);
		Q[h]++;
	}
	map<string , int> :: iterator it;
	for(it = Q.begin(); it != Q.end(); it++)
	{
		W.push_back({it -> second, it -> first});
	}
	sort(W.begin(), W.end());
	cout << W[W.size() - 1].second;
	return 0;	
}