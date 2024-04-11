#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define ll long long
#define X first
#define Y second
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
using namespace std;
int n,cnt;
string Name[50];
map<string,int> s;
vector<string> a1[50], a2[50];
int main()
{
	cin >> n;
	rep(i, 1, n)
	{
		string a;
		cin >> a;
		if(!s[a]) s[a] = ++ cnt, Name[cnt] = a;
		int t = s[a];
		int P;
		cin >> P;
		while(P --)
		{
			cin >> a;
			a1[t].pb(a);
		}
	}

	rep(i, 1, cnt)
	{
		int nn = a1[i].size();
		rep(j, 0, nn - 1)
		{
			bool find = 0;
			rep(k, 0, nn - 1)
			{
				bool flag = 1;
				if(a1[i][k].size() < a1[i][j].size()) continue;
				for(int l = 0; l < a1[i][j].size(); l ++)
					if(a1[i][j][l] != a1[i][k][a1[i][k].size() - a1[i][j].size() + l])
						flag = 0;
				if(flag && (a1[i][j] != a1[i][k] || j < k))find = 1;
			}
			if(!find) a2[i].pb(a1[i][j]);
		}
	}
	printf("%d\n",cnt);
	rep(i, 1, cnt)
	{
	    int nn = a2[i].size();
		cout << Name[i] << " " << nn << " ";
		rep(j, 0, nn - 1)
			cout << a2[i][j] << " ";
		puts("");
	}
	return 0;
}