#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    char ch;
    int lastGT = -1;
    bool possible = true;
    for (int i = 0; i < n; i++) {
		cin >> ch;
		if (ch == 'G' || ch == 'T') {
			if (lastGT == -1) {
				lastGT = i;
			} else {
				possible &= (i - lastGT) % k == 0;
				break;
			}
		} else if (lastGT >= 0 && (i - lastGT) % k == 0) {
			//
			possible &= ch != '#';
		}
    }
	cout << (possible ? "YES" : "NO") << endl;
    return 0;
}