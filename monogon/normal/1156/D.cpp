
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<pair<int, int> > edges;
int n, a, b, c;

int parent[2][200000], Size[2][200000];

int Find(int a, int t) {
	return parent[t][a] == -1 ? a : parent[t][a] = Find(parent[t][a], t);
}
void Union(int a, int b, int t) {
	int A = Find(a, t);
	int B = Find(b, t);
	if(Size[t][A] < Size[t][B]) swap(A, B);
	parent[t][B] = A;
	Size[t][A] += Size[t][B];
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		parent[0][i] = parent[1][i] = -1;
		Size[0][i] = Size[1][i] = 1;
	}
	for(int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		Union(a - 1, b - 1, c);
	}
	set<int> s[2];
	for(int i = 0; i < n; i++) {
		s[0].insert(Find(i, 0));
		s[1].insert(Find(i, 1));
	}
	long long count = 0;
	for(int i = 0; i < 2; i++) {
		while(s[i].size()) {
			long long sz = Size[i][*s[i].begin()];
			count += sz * (sz - 1);
			s[i].erase(s[i].begin());
		}
	}
	for(int i = 0; i < n; i++) {
		long long sz1 = Size[0][Find(i, 0)];
		long long sz2 = Size[1][Find(i, 1)];
		count += (sz1 - 1) * (sz2 - 1);
	}
	cout << count << endl;
}