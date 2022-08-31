#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <bitset>


using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 4000;
vector<int> eds[MAXN];
int arr[MAXN];
int n;
int cl[MAXN];

void dfs(int v, int c)
{
	cl[v] = c;
	for (int i = 0; i < eds[v].size(); ++i)
		if (!cl[eds[v][i]])
			dfs(eds[v][i], c);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			char c;
			cin >> c;
			if (c == '1')
			{
				eds[i].push_back(j);
				eds[j].push_back(i);
			}
		}
	int col = 1;
	for (int i = 0; i < n; ++i)
		if (!cl[i])
			dfs(i, col++);
	for (int i = 0; i < n; ++i)
	{
		int mn = i;
		for (int j = i + 1; j < n; ++j)
			if (cl[j] == cl[i] && arr[j] < arr[mn])
				mn = j;
		swap(arr[i], arr[mn]);
	}
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	return 0;
}