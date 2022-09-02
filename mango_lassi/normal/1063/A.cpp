#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	// Every palindrome starts and ends with the same letter
	sort(str.begin(), str.end());
	cout << str << '\n';
}