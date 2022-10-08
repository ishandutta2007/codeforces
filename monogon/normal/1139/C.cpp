
#define P 1000000007

#include <iostream>
#include <set>

using namespace std;

int n, k, u, v, x;
int parent[100000];
int Size[100000];

int Find(int a) {
	if(parent[a] == -1) return a;
	int f = Find(parent[a]);
	parent[a] = f;
	return f;
}
void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	parent[A] = B;
	Size[B] += Size[A];
}

long long mypow(long long n, int k) {
	if(k == 0) {
		return 1;
	}else if(k % 2 == 0) {
		long long p = mypow(n, k / 2);
		return (p * p) % P;
	}else {
		long long p = mypow(n, k - 1);
		return (n * p) % P;
	}
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		parent[i] = -1;
		Size[i] = 1;
	}
	for(int i = 0; i < n - 1; i++) {
		cin >> u >> v >> x;
		u--; v--;
		if(x == 0) {
			Union(u, v);
		}
	}
	set<int> Parents;
	for(int i = 0; i < n; i++) {
		Parents.insert(Find(i));
	}
	// total number of k-sequences is n^k
	long long sum = mypow(n, k);
	for(int p : Parents) {
		sum -= mypow(Size[p], k);
		sum = (sum % P + P) % P;
	}
	cout << sum << endl;
}