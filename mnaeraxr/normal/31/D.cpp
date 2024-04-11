#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int F[10100];
int C[10100];
int M[110][110];

int root(int a){
	return a == F[a] ? a : F[a] = root(F[a]);
}

bool join(int a, int b){
	a = root(a), b = root(b);
	if (a == b) return false;
	if (C[a] > C[b]) swap(a, b);
	C[b] += C[a];
	F[a] = b;
	return true;
}

void init(int t){
	for (int i = 0; i < t; ++i)
		F[i] = i, C[i] = 1;
}

int W, H, n;

int val(int x, int y){
	return H * x + y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> W >> H >> n;

	init(W * H);

	for (int i = 0; i < n; ++i){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2){
			for (int j = y1; j < y2; ++j){
				M[x1 - 1][j] |= 1;
			}
		}
		else{
			for (int j = x1; j < x2; ++j){
				M[j][y1 - 1] |= 2;
			}
		}
	}

	for (int i = 0; i < W; ++i){
		for (int j = 0; j < H; ++j){
			if (i + 1 != W && ((M[i][j] & 1) == 0)){
				join(val(i,j), val(i + 1, j));
			}
			if (j + 1 != H && ((M[i][j] & 2) == 0)){
				join(val(i,j), val(i, j + 1));
			}
		}
	}

	set<int> S;
	vector<int> V;
	for (int i = 0; i < W; ++i){
		for (int j = 0; j < H; ++j){
			int v = val(i,j);
			v = root(v);
			if (!S.count(v)) V.push_back(C[v]), S.insert(v);
		}
	}

	sort(V.begin(), V.end());
	for (int i = 0; i < SZ(V); ++i)
		cout << V[i] << " \n"[i + 1 == SZ(V)];

	return 0;
}