#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

#define DO(i) sort(P[i], P[i] + 3); do
#define WHILE(i) while (next_permutation(P[i], P[i] + 3))

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int64 P[8][3];
int64 D[28];

int64 sqr(int64 v){
	return v * v;
}

int64 dist(int x, int y){
	return sqr(P[x][0] - P[y][0]) + sqr(P[x][1] - P[y][1]) + sqr(P[x][2] - P[y][2]);
}

bool ok()
{
	for (int i = 0, t = 0; i < 8; ++i){
		for (int j = i + 1; j < 8; ++j){
			D[t++] = dist(i,j);
		}
	}
	sort(D, D + 28);

	if (!D[0]) return false;
	if (D[0] != D[11]) return false;
	if (D[12] != D[23]) return false;
	if (D[24] != D[27]) return false;
	if (2 * D[0] != D[12]) return false;
	if (D[0] + D[12] != D[24]) return false;
	return true;
}

void end(bool mode){
	if (mode){
		cout << "YES" << endl;
		for (int i = 0; i < 8; ++i){
			for (int j = 0; j < 3; ++j)
				cout << P[i][j] << " \n"[j + 1 == 3];
		}
	}
	else{
		cout << "NO" << endl;
	}

	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 3; ++j)
			cin >> P[i][j];
	}

	DO(0){ DO(1) { DO(2) { DO(3) { DO(4) { DO(5) { DO(6) {
		if (ok())
			end(true);
	} WHILE(6); } WHILE(5); } WHILE(4); } WHILE(3); } WHILE(2); } WHILE(1); } WHILE(0);

	end(false);

	return 0;
}