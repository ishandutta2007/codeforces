#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int is[maxn];

bool has[30];

// 0 : is not
// 1 : may be

int main()
{
	int n;
	cin >> n;
	fill(is , is + maxn , 1);
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		int t = 0;
		for(int j = 0; j < 26; j++)
			if(is[j])
				t++;
		char ch;
		string s;
		cin >> ch >> s;
		res += (t == 1 && ch != '.' && i != n - 1);
		memset(has , 0 , sizeof has);
		for(int j = 0; j < (int)s.size(); j++)
			has[s[j] - 'a'] = 1;
		for(int j = 0; j < 26; j++)
		{
			if(!is[j])
				continue;
			if(ch == '.' && has[j])
				is[j] = 0;
			if(ch == '!' && !has[j])
				is[j] = 0;
			if(ch == '?' && i != n - 1 && has[j])
				is[j] = 0;
		}
	}
	cout << res << endl;
}