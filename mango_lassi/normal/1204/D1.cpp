#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();

	int diff = 0;
	for (int i = n-1; i >= 0; --i) {
		if (str[i] == '0') ++diff;
		else {
			int j = i;
			while((j > 0) && (str[j-1] == '1')) --j;
			int r = j;
			while(i-j+1 > diff) {
				str[j] = '0';
				++j;
			}
			diff = max(0, diff - (i-r+1));
			i = r;
		}
	}
	cout << str << '\n';
}