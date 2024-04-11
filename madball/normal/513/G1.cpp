#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
typedef long long int64;

void reverse(vector<int> &ar, int l, int r) {
	for (int i = l; i < (l + r + 1) / 2; i++)
		swap(ar[i], ar[r + l - i]);
}

pair<int64, int64> getans(vector<int> &ar, int left) {
	int64 res1 = 0, res2 = 0;
	pair<int64, int64> wtf;
	if (left == 0) {
		for (int i = 0; i < ar.size(); i++)
			for (int j = i + 1; j < ar.size(); j++)
				if (ar[j] < ar[i])
					res1++;
		res2 = 1;
	}
	else {
		for (int i = 0; i < ar.size(); i++)
			for (int j = i; j < ar.size(); j++) {
				reverse(ar, i, j);
				wtf = getans(ar, left - 1);
				res1 += wtf.first;
				res2 += wtf.second;
				reverse(ar, i, j);
			}
	}
	return make_pair(res1, res2);
}

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/
	int64 n, k, i;
	cin >> n >> k;
	vector<int> ar(n);
	for (i = 0; i < n; i++)
		cin >> ar[i];
	cout.precision(20);
	pair<int64, int64> wtf;
	wtf = getans(ar, k);
	cout << (double)(wtf.first) / wtf.second;

	return 0;
}