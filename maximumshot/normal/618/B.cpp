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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

vec< vec< int > > get_matrix(vec< int > & a) {
	int n = (int)a.size();
	vec< vec< int > > mat(n, vec< int >(n));
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(i == j) mat[i][j] = 0;
			else mat[i][j] = min(a[i], a[j]);
		}
	}
	return mat;
}

vec< int > get_permutation(vec< vec< int > > & mat) {
	int n = (int)mat.size();
	vec< char > used(n);
	vec< int > ans;
	for(int i = 0;i < n;i++) {
		int mx = *max_element(ALL(mat[i]));
		for(int j = mx - 1;j < n;j++) {
			if(!used[j]) {
				used[j] = 1;
				ans.push_back(j + 1);
				break;
			}
		}
	}
	return ans;
}

bool solve() {

	int n;
	cin >> n;

	vec< vec< int > > mat(n, vec< int >(n)); 
	
	for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cin >> mat[i][j];

	vec< int > a = get_permutation(mat);

	for(auto i : a) cout << i << ' ';
	cout << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}