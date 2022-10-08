
#include <iostream>
#include <vector>

using namespace std;

int n, m, k, a, b;

int parent[500000];
int Size[500000];

int Find(int a) {
	if(parent[a] == -1) return a;
	int x = Find(parent[a]);
	parent[a] = x;
	return x;
}
void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if(A == B) return;
	if(Size[A] < Size[B]) {
		swap(A, B);
	}
	Size[A] += Size[B];
	parent[B] = A;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		parent[i] = -1;
		Size[i] = 1;
	}
	for(int i = 0; i < m; i++) {
		cin >> k;
		if(k > 0) {
			cin >> a;
			for(int j = 1; j < k; j++) {
				cin >> b;
				Union(a - 1, b - 1);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		cout << Size[Find(i)] << " ";
	}
}