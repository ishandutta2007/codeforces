
#include <iostream>
#include <set>

using namespace std;

int n;
int a[100001];
int count[100001];

set<int> counts;
// the number of ribbons with count i
int num[100001];

int main() {
	cin >> n;
	int x = 1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		count[a[i]]++;
		num[count[a[i]]]++;
		if(count[a[i]] > 1) {
			num[count[a[i]] - 1]--;
			if(num[count[a[i]] - 1] == 0) {
				counts.erase(count[a[i]] - 1);
			}
		}
		counts.insert(count[a[i]]);
		if(counts.size() <= 2) {
			int val1 = *counts.begin();
			int count1 = num[val1];
			int val2 = -1;
			int count2 = 0;
			if(counts.size() == 2) {
				val2 = *next(counts.begin());
				count2 = num[val2];
			}
			if(((abs(val1 - val2) == 1 && ((count1 == 1 && val1 > val2) || (count2 == 1 && val2 > val1))) ||
					(val1 == 1 && val2 == -1) ||
					(val2 == -1 && count1 == 1) ||
					(val1 == 1 && count1 == 1) ||
					(val2 == 1 && count2 == 1))) {
				x = i + 1;
			}
		}
	}
	cout << x << endl;
	return 0;
}