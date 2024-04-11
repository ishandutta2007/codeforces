
#include <iostream>

using namespace std;

int n;
int a[100000];
int count[11];

int main() {
	cin >> n;
	int x = 1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		count[a[i]]++;
		int val1 = count[a[i]];
		int count1 = 0;
		int val2 = -1;
		int count2 = 0;
		int j = 1;
		for(; j <= 10; j++) {
			if(count[j] == val1) {
				count1++;
			}else if(count[j] > 0 && (val2 == -1 || count[j] == val2)) {
				count2++;
				val2 = count[j];
			}else if(val2 != -1 && count[j] > 0) {
				break;
			}
		}
		if(j > 10 && ((abs(val1 - val2) == 1 && ((count1 == 1 && val1 > val2) || (count2 == 1 && val2 > val1))) ||
				(val1 == 1 && val2 == -1) ||
				(val2 == -1 && count1 == 1) ||
				(val1 == 1 && count1 == 1) ||
				(val2 == 1 && count2 == 1))) {
			x = i + 1;
		}
	}
	cout << x << endl;
	return 0;
}