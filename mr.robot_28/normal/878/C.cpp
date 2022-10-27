#include<bits/stdc++.h>
using namespace std;

vector <bool> type;
vector <vector <int> > matrix1;
vector <vector <int> > matrix2;
vector <set <pair <int, int> > > st1;
vector <set <pair <int, int> > > st2;
int n, k;
vector <int> dsu;
int pred(int a)
{
	if(a == dsu[a]) return a;
	else return dsu[a] = pred(dsu[a]);
}
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	cin >> n >> k;
	vector <int> rang(n, 1);
	st1.resize(k);
	st2.resize(k);
	dsu.resize(n);
	for(int i = 0; i < n; ++i)
	{
		dsu[i] = i;
	}
	matrix1.resize(n, vector <int> (k));
	matrix2.resize(n, vector <int> (k));
	int maxv = 0;
	for(int i = 0; i < n; i++)
	{
		int cnt = 0;
		for(int j = 0; j < k; j++)
		{
			int a;
			cin >> a;
			matrix1[i][j] = matrix2[i][j] = a;
		}
		for(int j = 0; j < k; j++){
			int a = matrix1[i][j];
			set <pair <int, int> > :: iterator it;
			it = st1[j].lower_bound({a, 0});
			if(it != st1[j].end())
			{
				cnt = 1;
			}
			for(; it != st1[j].end();)
			{
				int ind = pred(it -> second);
				bool flag = false;
				for(int j = 0; j < k; j++)
				{
					if(matrix1[ind][j] <= matrix2[i][j])
					{
						flag = true;
					}
				}
				if(flag)
				{
					rang[i] += rang[ind];
					dsu[ind] = i;
					it++;
					for(int q = 0; q < k; q++)
					{
					matrix1[i][q] = min(matrix1[ind][q], matrix1[i][q]);
					matrix2[i][q] = max(matrix2[i][q], matrix2[ind][q]);
						st1[q].erase({matrix2[ind][q], ind});
					}
				}
				else
				{
					break;
				}
			}
		}
		for(int j = 0; j < k; j++)
		{
			st1[j].insert({matrix2[i][j], i});
		}
		if(cnt == 0)
		{
			maxv = i;
		}
		cout << rang[pred(maxv)] << "\n";
	}
	return 0;
}