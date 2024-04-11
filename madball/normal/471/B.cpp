#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct ToDo {
	int index, diff;
	ToDo() {}
	bool operator < (ToDo const &td) const {
		return diff < td.diff;
	}
	bool operator == (ToDo const &td) const {
		return diff == td.diff;
	}
};

int main() {
	int n;
	cin >> n;
	vector<ToDo> plan (n);
	for (int i = 0; i < n; i++) {
		cin >> plan[i].diff;
		plan[i].index = i + 1;
	}

	sort(plan.begin(), plan.end());
	int pairs = 0;
	for (int i = 0; i < n - 1; i++)
		if (plan[i] == plan[i + 1])
			pairs++;

	if (pairs < 2)
		cout << "NO";
	else {
		cout << "YES\n";
		bool first = true;
		for (int i = 0; i < n; i++) {
			cout << plan[i].index << ' ';
			if ((i > 0 ? plan[i] == plan[i - 1] : false) && first) {
				swap(plan[i], plan[i - 1]);
				first = false;
			}
		}

		cout << '\n';
		first = true;
		for (int i = 0; i < n; i++) {
			cout << plan[i].index << ' ';
			if (i > 0 ? plan[i] == plan[i - 1] : false) {
				if (!first)
					swap(plan[i], plan[i - 1]);
				first = false;
			}
		}

		cout << '\n';
		for (int i = 0; i < n; i++)
			cout << plan[i].index << ' ';
	}

	return 0;
}