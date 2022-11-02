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

int N;

int main()
{
	puts("YES");
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		int x, y;
		scanf("%*d%*d%d%d", &x, &y);
		printf("%d\n", ((x+(int)1e9)%2*2 + (y+(int)1e9)%2)+1);
	}
}