#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = 100500;
const int LEN = 100500;
char str[LEN];
vector <int> v[N];

int p[N];
string id2name[N], id2path[N];
map <string, int> name2id, path2id;
vector <vector <int> > answer;

int getId(map <string, int> &m, string s, string ar[] )
{
	if (m.count(s) == 0)
	{
		int sz = (int) m.size();
		ar[sz] = s;
		m[s] = sz;
	}
	return m[s];
}

bool cmp(const int &a, const int &b)
{
	if ( (int) v[a].size() != (int) v[b].size() )
		return (int) v[a].size() < (int) v[b].size();
	for (int i = 0; i < (int) v[a].size(); i++)
		if (v[a][i] != v[b][i] )
			return v[a][i] < v[b][i];
	return false;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		int len = strlen(str);
		int b = 7;
		while (b < len && str[b] != '/')
			b++;
		string name = string(str, str + b);
		string path = string(str + b, str + len);
	
		v[getId(name2id, name, id2name) ].push_back(getId(path2id, path, id2path) );
	}
	int k = (int) name2id.size();
	for (int i = 0; i < k; i++)
	{
		p[i] = i;
		sort(v[i].begin(), v[i].end() );
		v[i].resize(unique(v[i].begin(), v[i].end() ) - v[i].begin() );
	}
	sort(p, p + k, cmp);
	for (int i = 0; i < k;)
	{
		int j = i;
		while (j < k && !cmp(p[i], p[j] ) )
			j++;
		if (j > i + 1)
		{
			vector <int> cur;
			for (int h = i; h < j; h++)
				cur.push_back(p[h] );
			answer.push_back(cur);
		}
		i = j;
	}
	printf("%d\n", (int) answer.size() );
	for (auto &x : answer)
	{
		for (auto id : x)
			printf("%s ", id2name[id].c_str() );
		printf("\n");
	}


	return 0;
}