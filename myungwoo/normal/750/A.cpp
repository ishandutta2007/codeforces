#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

int N, K;

int main()
{
	cin >> N >> K; K = 240 - K;
	int ans = 0;
	for (int i=1;i<=N;i++){
		if (K < 5*i) break;
		K -= 5*i; ans++;
	}
	cout << ans << endl;
}