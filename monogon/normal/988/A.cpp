
#include <iostream>
#include <set>

using namespace std;

int n, k;
int a[100];
int team[100];
int count = 0;

int main() {
	cin >> n >> k;
	for(int i = 0; i < n && count < k; i++) {
		cin >> a[i];
		int j = 0;
		for(j = 0; j < count; j++) {
			if(a[i] == a[team[j]]) {
				break;
			}
		}
		if(j == count) {
			team[count++] = i;
		}
	}
	if(count == k) {
		cout << "YES" << endl;
		for(int i = 0; i < k; i++) {
			cout << (team[i] + 1) << " ";
		}
		cout << endl;
	}else {
		cout << "NO" << endl;
	}
}