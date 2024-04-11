#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int N[3], T[3];
int R[4];
queue<int> Q[3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;
	cin >> N[0] >> N[1] >> N[2];
	cin >> T[0] >> T[1] >> T[2];

	R[0] = 0;
	R[1] = R[0] + T[0];
	R[2] = R[1] + T[1];
	R[3] = R[2] + T[2];

	int b = 0;

	for (int j = 0; j < k; ++j){
		for (int i = 0; i < 3; ++i){
			int c = b + R[i];
			while (!Q[i].empty() && Q[i].front() <= c) Q[i].pop();
			if ((int)Q[i].size() >= N[i]){
				b = max(b, Q[i].front() - R[i]);
			}
		}
		for (int i = 0; i < 3; ++i){
			Q[i].push(b + R[i + 1]);
			while ((int)Q[i].size() > N[i]) Q[i].pop();
		}
	}

	cout << b + R[3] << endl;


	return 0;
}