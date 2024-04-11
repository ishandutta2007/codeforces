
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n;
int a[200000];
multiset<int> s;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int l = 0;
	int maxlen = 1;
	int maxidx = 0;
	for(int i = 1; i < n; i++) {
		if(a[i] > a[i - 1] + 1) {
			if(i - l > maxlen) {
				maxlen = i - l;
				maxidx = l;
			}
			l = i;
		}else if(a[i] == a[i - 1] + 1) {
			int j = 0;
			for(j = 0; i + j < n && a[i + j] == a[i]; j++);
			if(j == 1) {
				if(i + j - l > maxlen) {
					maxlen = i + j - l;
					maxidx = l;
				}
				l = i + j - 1;
			}
			i = i + j - 1;
		}
	}
	if(n - l > maxlen) {
		maxlen = n - l;
		maxidx = l;
	}
	cout << maxlen << endl;

	int mymin = a[maxidx];
	int mymax = a[maxidx + maxlen - 1];
	for(int i = 0; i < maxlen; i++) {
		s.insert(a[maxidx + i]);
	}
	for(int i = mymax; i > mymin; i--) {
		cout << i << " ";
		s.erase(s.find(i));
	}
	while(!s.empty()) {
		cout << *s.begin() << " ";
		s.erase(s.begin());
	}
}