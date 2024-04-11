#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

char s[5010];
bool halfPal[5010][5010];
int tot, len;
int trie[25000001][3];

void push(int st){
	int cur = 0;
	for (int i = st; i < len; ++i){
		int nxt = s[i] - 'a';
		if (!trie[cur][nxt]){
			trie[cur][nxt] = tot++;
		}
		cur = trie[cur][nxt];
		if (halfPal[st][i]) trie[cur][2]++;
	}
}

char ans[5100];
int pos;

bool dfs(int s, int &k){
	k -= trie[s][2];
	if (k <= 0)	return true;
	if (trie[s][0] && dfs(trie[s][0], k))
	{
		ans[pos++] = 'a';
		return true;
	}
	if (trie[s][1] && dfs(trie[s][1], k)){
		ans[pos++] = 'b';
		return true;
	}
	return false;
}

int main()
{
	scanf("%s", s);
	len = strlen(s);

	for (int i = 1; i <= len; ++i){
		for (int j = 0; j + i - 1 < len; ++j){
			if (s[j] != s[j + i - 1]) continue;
			if (j + 2 > j + i - 3 || halfPal[j + 2][j + i - 3])
				halfPal[j][j + i - 1] = true;
		}
	}

	tot = 1;
	for (int i = 0; i < len; ++i)
		push(i);

	int k;
	scanf("%d", &k);

	dfs(0, k);
	while (pos) putchar(ans[--pos]);
	putchar('\n');

	return 0;
}