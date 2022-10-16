#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int BIT[MAXN];

void update(int idx, int v){
	while (idx < MAXN){
		BIT[idx] += v;
		idx += idx&-idx;
	}
}

int read(int idx){
	int ans = 0;
	while (idx){
		ans += BIT[idx];
		idx -= idx&-idx;
	}
	return ans;
}

int range(int a, int b){
	assert(a <= b);
	return read(b) - read(a);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	int b = 1, e = n, flip = 0;
	for (int i = 1; i <= n; ++i) update(i, 1);

	for (int i = 0; i < q; ++i){
		int m; cin >> m;
		int width = e - b + 1;
		if (m == 1)
		{
			int v; cin >> v;
			if (!flip){
				if (2 * v <= width)
				{
					b += v;
					for (int j = 0; j < v; ++j)
						update(b + j, range(b - j - 2, b - j - 1));
				}
				else{
					flip ^= 1;
					e -= width - v;
					for (int j = 0; j < width - v; ++j)
						update(e - j, range(e + j, e + j + 1));
				}
			}
			else{
				if (2 * v <= width){
					e -= v;
					for (int j = 0; j < v; ++j)
						update(e - j, range(e + j, e + j + 1));
				}
				else{
					flip ^= 1;
					b += width - v;
					for (int j = 0; j < width - v; ++j)
						update(b + j, range(b - j - 2, b - j - 1));
				}
			}
		}
		else{
			int u, v;
			cin >> u >> v;
			if (!flip){
				cout << range(u + b - 1, b + v - 1) << endl;
			}
			else{
				cout << range(e - v,e - u) << endl;
			}
		}
	}

	return 0;
}