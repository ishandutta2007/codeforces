#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int N; //  -  
int n, m, k;

int f(int x, int y, int z) {
	return x * m * k + y * k + z;
}

vec< vec< int > > G;

void add_edge(int u, int v) {
	G[u].push_back(v);
}

bool solve() {

	scanf("%d %d %d", &n, &m, &k);

	// n * m * k

	N = n * m * k;

    bool cube[100][100][100];

	for(int x = 0;x < n;x++) {
		char C;
		for(int y = 0;y < m;y++) {
			for(int z = 0;z < k;z++) {
				scanf(" %c", &C);
				cube[x][y][z] = C - '0';
			}
		}
	}

	G.resize(N);
	
	for(int x = 0;x < n;x++) {
		for(int y = 0;y < m;y++) {
			for(int z = 0;z < k;z++) {
				if(!cube[x][y][z]) continue;
				if(x + 1 < n && cube[x + 1][y][z]) add_edge(f(x, y, z), f(x + 1, y, z));
				if(y + 1 < m && cube[x][y + 1][z]) add_edge(f(x, y, z), f(x, y + 1, z));
				if(z + 1 < k && cube[x][y][z + 1]) add_edge(f(x, y, z), f(x, y, z + 1));
			}
		}
	}

	vec< pair< pii, int > > edge;

    map< ll, int > Q;

	for(int s = 0;s < N;s++) {
		for(int mid : G[s]) {
			for(int f : G[mid]) {
				// s -> mid -> f
				ll val = s * 1000001ll + f;
				if(Q.count(val)) Q.erase(val);
				else Q[val] = mid;
			}
		}
	}

    set< int > ans;
    for(auto it : Q) ans.insert(it.second);

    cout << (int)ans.size() << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}