#include <bits/stdc++.h>
using namespace std;

map<string, int> id;
string Text[1101], Name[110];
int n, m, can[110][110], bef[110][110], um[110], is[110][110];

void Out(int x, int y)
{
	if(x > 1) Out(x - 1, bef[x][y]), cout << Name[y] << ":" << Text[x - 1] << endl;
}

void Init()
{
    id.clear();
	memset(is, 0, sizeof(is));
	memset(can, 0, sizeof(can));

	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> Name[i], id[Name[i]] = i;
	cin >> m;
	getline(cin, Text[0]);
	for(int i = 1; i <= m; i ++)
		getline(cin, Text[i]);

    for(int i = 1; i <= m; i ++)
	{
		int t = -1;
		for(int j = 0; j < (int)Text[i].size(); j ++)
			if(Text[i][j] == ':') {t = j; break;}
		if(Text[i][0] == '?') um[i] = -1;
		else um[i] = id[Text[i].substr(0, t)];
		Text[i] = Text[i].substr(t + 1) + ' ';
		int last = -1;
		for(int j = 0; j < (int)Text[i].size(); j ++)
		    if(Text[i][j] == ',' || Text[i][j] == ' ' || Text[i][j] == '.' || Text[i][j] == '!' || Text[i][j] == '?')
            {
                if(last < j - 1)
                {
                    int t = id[Text[i].substr(last + 1, j - last - 1)];
                    if(t) is[i][t] = 1;
                }
                last = j;
            }
		Text[i] = Text[i].substr(0, Text[i].size() - 1);
	}
}

void solve()
{
	Init();
	can[1][0] = 1;
	for(int i = 1; i <= m; i ++)
		for(int j = min(1, i - 1); j <= n; j ++)
		{
			if(!can[i][j]) continue;
			if(um[i] != -1 && j != um[i]) can[i + 1][um[i]] = 1, bef[i + 1][um[i]] = j;
			else if(um[i] == -1)
			{
				for(int nxt = 1; nxt <= n; nxt ++)
				{
					if(is[i][nxt] || j == nxt) continue;
					can[i + 1][nxt] = 1, bef[i + 1][nxt] = j;
				}
			}
		}

	for(int i = 1; i <= n; i ++)
		if(can[m + 1][i])
		{
			Out(m + 1, i);
			return;
		}
	puts("Impossible");
}
int main()
{
	int Case;
	cin >> Case;
	while(Case --) solve();
	return 0;
}