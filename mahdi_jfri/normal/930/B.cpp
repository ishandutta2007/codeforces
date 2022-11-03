#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ld long double

const int maxn = 1e5 + 20;

vector<int> shit[30];

int t[30];

int main()
{
	string s;
	cin >> s;

	int n = s.size();

	s += s;

	for(int i = 0; i < n; i++)
		shit[s[i] - 'a'].pb(i);

	int sh = 0;
	for(int i = 0; i < 26; i++)
	{
		int res = 0;
		for(int j = 0; j < n; j++)
		{
			int ans = 0;
			memset(t , 0 , sizeof t);
			for(int x : shit[i])
				t[s[x + j] - 'a']++;
			
			for(int k = 0; k < 26; k++)
				if(t[k] == 1)
					ans++;
			res = max(res , ans);
		}
		sh += res;
	}

	cout << fixed << setprecision(20) << (ld)sh / (ld)(n) << endl;
}