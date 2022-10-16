#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<pii> v(3);
string s = "#ABC";

int area;
int l;

int mat[200][200];

void print(){
	printf("%d\n", l);
	for (int i = 0; i < l; ++i){
		for (int j = 0; j < l; ++j){
			putchar(s[mat[i][j]]);
			assert(mat[i][j] != 0);
		}
		putchar('\n');
	}
	exit(0);	
}

void solve(int idx, int s0, int s1){
	// cout << idx << " " << s0 << " " << s1 << endl;
	memset(mat, 0, sizeof mat);

	pii p0 = idx >= 1 ? v[0] : v[1];
	pii p1 = idx <= 1 ? v[2] : v[1];
	pii p2 = v[idx];
	int v0 = idx >= 1 ? 0 : 1;
	int v1 = idx <= 1 ? 2 : 1;
	int v2 = idx;

	if (s0) swap(p0.first, p0.second);
	if (s1) swap(p1.first, p1.second);
	
	for (int i = 0; i < p0.first; ++i){
		for (int j = 0; j < p0.second; ++j){
			mat[i][j] = v0 + 1;			
		}
	}

	// print();

	for (int i = 0; i < p1.first; ++i){
		for (int j = 0; j < p1.second; ++j){
			if (mat[l - i - 1][l - j - 1]) return;
			mat[l - i - 1][l - j - 1] = v1 + 1;
		}
	}

	// print();

	int x1 = -1, y1 = -1;
	for (int i = 0; i < l && x1 == -1; ++i){
		for (int j = 0; j < l && x1 == -1; ++j){
			if (!mat[i][j])
				x1 = i, y1 = j;
		}
	}

	int sx = 0, sy = 0;
	for (;x1 + sx < l && mat[x1 + sx][y1] == 0; ++sx);
	for (;y1 + sy < l && mat[x1][y1 + sy] == 0; ++sy);

	// cout << x1 << " " << sx << endl;
	// cout << y1 << " " << sy << endl;

	if (pii(sx, sy) == p2 || pii(sy, sx) == p2){
		for (int i = 0; i < sx; ++i)
			for (int j = 0; j < sy; ++j)
			{
				if (mat[x1 + i][y1 + j]) return;
				mat[x1 + i][y1 + j] = v2 + 1;
			}
		print();
	}

}

int main()
{

	int mx = 0;
	for (int i = 0; i < 3; ++i){
		scanf("%d%d", &v[i].first, &v[i].second);
		area += v[i].first * v[i].second;
		mx = max(v[i].first, mx);
		mx = max(v[i].second, mx);
	}
	for (l = 0; l * l < area; ++l);
	
	if (l * l > area || mx > l){
		printf("-1\n");
		exit(0);
	}

	// cout << "HERE" << endl;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				solve(i, j, k);

	printf("-1\n");


	return 0;
}