#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

typedef vector<short int> strint;

ostream &operator << (ostream &out, strint &a) {
	for (int i = a.size() - 1; i >= 0; i--)
		out << a[i];
	return out;
}

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/

	int n, i, j, k, need, cursum;
	strint cur;
	cin >> n;
	vector<int> sums(n);
	for (i = 0; i < n; i++)
		cin >> sums[i];
	need = sums[0];
	while (need > 0) {
		cur.push_back(min(9, need));
		need -= cur[cur.size() - 1];
	}
	cout << cur << '\n';

	for (k = 1; k < n; k++) {
		cursum = sums[k - 1];
		if (sums[k] > cursum) {
			for (i = 0; cursum < sums[k]; cursum++) {
				while ((i < cur.size()) && (cur[i] == 9))
					i++;
				if (i == cur.size())
					cur.push_back(0);
				cur[i]++;
			}
		}
		else {
			need = sums[k];
			for (i = 0;; i++) {
				need += cur[i];
				if (need > cursum)
					break;
			}
			if (i == cur.size() - 1) {
				cur.push_back(0);
				j = i + 1;
			}
			else {
				for (j = i + 1; (j < cur.size()) && (cur[j] == 9); j++);
				if (j == cur.size())
					cur.push_back(0);
			}
			cur[j]++;
			cursum++;
			for (j--; j >= 0; j--) {
				while (cur[j] > 0) {
					cur[j]--;
					cursum--;
				}
			}
			for (i = 0; cursum < sums[k]; cursum++) {
				while ((i < cur.size()) && (cur[i] == 9))
					i++;
				if (i == cur.size())
					cur.push_back(0);
				cur[i]++;
			}
		}
		cout << cur << '\n';
	}

	return 0;
}