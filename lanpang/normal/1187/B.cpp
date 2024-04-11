#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , m , ap[26] , ans;
vector<int> fi[26];
string s;

int main()
{
	int i , j;
	cin >> n;
	cin >> s;
	for (i = 0 ; i < n ; i++)
		fi[s[i]-'a'].push_back(i);
	cin >> m;
	for (i = 1 ; i <= m ; i++)
	{
		for (j = 0 ; j < 26 ; j++)
			ap[j] = 0;
		cin >> s;
		for (auto j: s)
			ap[j-'a']++;
		ans = 0;
		for (j = 0 ; j < 26 ; j++)
			if (ap[j]) ans = max(ans,fi[j][ap[j]-1]+1);
		printf("%d\n",ans);
	}
	return 0;
}