#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	for (int p1 = 1, p2 = K + 1, j = 0; j <= K; ++j)
	{
		if (j & 1)
			cout << p2-- << " ";
		else
			cout << p1++ << " ";
	}

	for (int j = K + 2; j <= N; ++j)
		cout << j << " ";

	cout << endl;

	return 0;
}