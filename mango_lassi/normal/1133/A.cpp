#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h1, m1, h2, m2;
	string str;
	cin >> str;

	h1 = 0;
	h1 += 10 * (str[0] - '0');
	h1 += (str[1] - '0');
	m1 = 0;
	m1 += 10 * (str[3] - '0');
	m1 += str[4] - '0';

	cin >> str;

	h2 = 0;
	h2 += 10 * (str[0] - '0');
	h2 += (str[1] - '0');
	m2 = 0;
	m2 += 10 * (str[3] - '0');
	m2 += str[4] - '0';
	

	int min1 = 60 * h1 + m1;
	int min2 = 60 * h2 + m2;
	int min3 = (min1 + min2) / 2;
	int hour = min3 / 60;
	int minute = min3 % 60;

	if (hour < 10) cout << "0" << hour;
	else cout << hour;

	cout << ":";

	if (minute < 10) cout << "0" << minute;
	else cout << minute;

	cout << endl;
}