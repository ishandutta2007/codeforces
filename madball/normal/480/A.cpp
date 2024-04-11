#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct Exam {
	int l, r;
	Exam() {}
	bool operator < (Exam const &p) const {
		if (r == p.r)
			return (l < p.l);
		else
			return (r < p.r);
	}
};

int main() {
	int n;
	cin >> n;
	vector<Exam> exams(n);
	for (int i = 0; i < n; i++)
		cin >> exams[i].r >> exams[i].l;

	sort(exams.begin(), exams.end());

	int prev, cur;
	for (int i = 0; i < n; i++) {
		cur = (((i == 0) ? true : exams[i].l >= prev) ? exams[i].l : exams[i].r);
		prev = cur;
	}

	cout << cur;
	return 0;
}