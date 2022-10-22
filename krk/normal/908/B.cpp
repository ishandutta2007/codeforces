#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 52;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m;
char B[Maxn][Maxn];
int sr, sc, tr, tc;
string s;
vector <int> seq;
int res;

bool inBounds(int r, int c) { return 0 <= r && r < n && 0 <= c && c < m; }

bool Check()
{
	int curr = sr, curc = sc;
	for (int i = 0; i < s.length() && inBounds(curr, curc) && B[curr][curc] != '#' && (curr != tr || curc != tc); i++) {
		int tk = seq[s[i] - '0'];
		curr += dy[tk], curc += dx[tk];
	}
	return curr == tr && curc == tc;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf(" %c", &B[i][j]);
			if (B[i][j] == 'S') sr = i, sc = j;
			else if (B[i][j] == 'E') tr = i, tc = j;
		}
	cin >> s;
	for (int i = 0; i < Maxd; i++)
		seq.push_back(i);
	do {
		if (Check()) res++;
	} while (next_permutation(seq.begin(), seq.end()));
	printf("%d\n", res);
	return 0;
}