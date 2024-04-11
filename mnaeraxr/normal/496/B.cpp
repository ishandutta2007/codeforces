#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

char c[maxn];
int pos, shift, n;

int digit(int p, int s){
	return (c[p % n] - '0' + s) % 10;
}

bool compare(int p, int s){
	for (int i = 0; i < n; ++i){
		int d1 = digit(i + p, s);
		int d2 = digit(i + pos, shift);
		if (d1 != d2) return d1 < d2;
	}
	return false;
}

void print(){
	for (int i = 0; i < n; ++i)
		cout << digit(i + pos, shift);
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> c;

	pos = shift = 0;

	for (int i = 0; i < 10; ++i){
		for (int j = 0; j < n; ++j){
			if (compare(j, i))
				pos = j, shift = i;
		}
	}

	print();

	return 0;
}