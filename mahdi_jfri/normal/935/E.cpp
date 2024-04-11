#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e4 + 20;
const int maxd = 1e2 + 20;

ll match[maxn] , mx[maxn][maxd] , mn[maxn][maxd] , id , sz[maxn];

ll tmpmn[maxn] , tmpmx[maxn];

pair<int , int> x[maxn];

vector<int> shits;

int main()
{
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxd; j++)
		{
			tmpmn[i] = 1e9;
			tmpmx[i] = -1e9;
			mx[i][j] = -1e9;
			mn[i][j] = 1e9;
		}
	string s , tmp;
	cin >> tmp;

	ll n = tmp.size() , p , m;
	cin >> p >> m;

	for(int i = 0; i < n; i++)
	{
		if('0' <= tmp[i] && tmp[i] <= '9')
			s += "(" , s += tmp[i]  , s += ")";
		else
			s += tmp[i];
	}

	n = s.size();

	stack<int> st;

	for(int i = 0; i < n; i++)
	{
		if(s[i] != ')' && s[i] != '(')
			continue;
		if(s[i] == '(')
			st.push(i);
		else
		{
			int k = st.top();
			st.pop();
			match[i] = k;
			match[k] = i;
			x[id++] = {i - k - 1 , i};
		}
	}
	sort(x , x + id);

	for(int i = 0; i < id; i++)
	{
		int k = x[i].second;
		if(x[i].first == 1)
		{
			mx[k][0] = mn[k][0] = s[k - 1] - '0';
			continue;
		}
		int L = match[match[k] + 1];
		int R = k - 1;

		for(int j = 0; j <= min(sz[L] , min(p , m)); j++)
			for(int k = 0; k <= min(sz[R] , min(p , m)); k++)
			{
				int kir = (p < m);
				tmpmx[j + k + kir] = max(tmpmx[j + k + kir] , mx[L][j] + mx[R][k]);
				tmpmn[j + k + kir] = min(tmpmn[j + k + kir] , mn[L][j] + mn[R][k]);

				tmpmx[j + k + 1 - kir] = max(tmpmx[j + k + 1 - kir] , mx[L][j] - mn[R][k]);
				tmpmn[j + k + 1 - kir] = min(tmpmn[j + k + 1 - kir] , mn[L][j] - mx[R][k]);
			}

		sz[k] = sz[L] + sz[R] + 1;

		for(int j = 0; j <= min(sz[k] , min(p , m)); j++)
		{
			mx[k][j] = tmpmx[j] , tmpmx[j] = -1e9;
			mn[k][j] = tmpmn[j] , tmpmn[j] = 1e9;
		}

	}

	cout << mx[n - 1][min(p , m)] << endl;
}