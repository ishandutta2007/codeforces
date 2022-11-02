#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

int N, M;
int go[51][4];
char S[51][51];

int get_type(char c)
{
	if (isdigit(c)) return 1;
	if ('a' <= c && c <= 'z') return 2;
	if (strchr("#*&", c)) return 3;
	return 0;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=1;i<=N;i++){
		scanf("%s", S[i]);
		for (int j=0;j<4;j++) go[i][j] = 200;
		for (int j=0;j<M;j++){
			int d = min(j, M-j);
			int t = get_type(S[i][j]);
			go[i][t] = min(go[i][t], d);
		}
	}
	int ans = 600;
	for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) for (int k=1;k<=N;k++){
		if (i == j || j == k || k == i) continue;
		int v = min(ans, go[i][1] + go[j][2] + go[k][3]);
		ans = min(ans, v);
	}
	cout << ans << endl;
}