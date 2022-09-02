#include<stdio.h>
#include<map>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MX = 100005;
const int MM = 1000000007;

vector<int> G[MX];
int cnt[MX];
int main()
{
	int N, a, b;
	scanf("%d", &N);
	for(int i = 1; i < N; i++){
		scanf("%d%d", &a, &b);
		cnt[a]++; cnt[b]++;
	}
	int x = 0;
	for(int i = 1; i <= N; i++) if( cnt[i] == 1 ) x++;
	ll m = 1;
	for(int i = 1; i <= N-x; i++) m = m*2%MM;
	printf("%lld\n", ((N-x) * m + x * m*2) % MM);
}