#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define sz(v) ((int)(v).size())

int N;
vector <int> T[4];

int main()
{
	int i, k;
	scanf("%d", &N);
	for (i=1;i<=N;i++){
		scanf("%d", &k);
		T[k].push_back(i);
	}
	int ans = min(sz(T[1]), min(sz(T[2]), sz(T[3])));
	printf("%d\n", ans);
	for (i=0;i<ans;i++) printf("%d %d %d\n", T[1][i], T[2][i], T[3][i]);
}