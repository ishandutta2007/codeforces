#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int get(int64 n, int64 pos){
	if (n < 2) return n;
	int64 size = (1LL << __lg(n)) - 1;
	if (pos <= size) return get(n / 2, pos);
	if (size + 1 == pos) return n & 1;
	return get(n / 2, pos - size - 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 n, l, r;

	cin >> n >> l >> r;

	int answer = 0;

	for (int64 i = l; i <= r; ++i)
		answer += get(n, i);

	cout << answer << endl;

	return 0;
}