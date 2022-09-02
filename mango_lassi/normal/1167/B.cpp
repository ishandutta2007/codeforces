#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

pair<int, int> getPair(int v) {
	// 4, 8, 15, 16, 23, 42
	// 2^2, 2^3, 2^4, 3*5, 2*3*7, 23
	int fives = (v % 5 ? 0 : 1);
	int sevens = (v % 7 ? 0 : 1);
	int primes = (v % 23 ? 0 : 1);
	if (primes) return {23, v / 23};
	if (sevens) return {42, v / 42};
	if (fives) return {15, v / 15};

	int twos = 0;
	while(v % 2 == 0) {
		++twos;
		v /= 2;
	}
	if (twos == 5) return {4, 8};
	if (twos == 6) return {4, 16};
	if (twos == 7) return {8, 16};
	return {-1, -1};
}
pair<int, int> ask(int a, int b) {
	cout << "? " << a << ' ' << b << endl;
	int v;
	cin >> v;
	return getPair(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Find pairs
	vector<int> vals = {4, 8, 16, 15, 23, 42};
	pair<int, int> one_two = ask(1, 2);
	pair<int, int> three_four = ask(3, 4);

	pair<int, int> five_six = {-1, -1};
	for (auto v : vals) {
		if (v != one_two.first && v != one_two.second && v != three_four.first && v != three_four.second) {
			if (five_six.first == -1) {
				five_six.first = v;
			} else {
				five_six.second = v;
			}
		}
	}

	// Order correctly
	pair<int, int> one_three = ask(1, 3);
	pair<int, int> three_five = ask(3, 5);
	if (one_three.first == one_two.second || one_three.second == one_two.second) swap(one_two.first, one_two.second);
	if (one_three.first == three_four.second || one_three.second == three_four.second) swap(three_four.first, three_four.second);
	if (three_five.first == five_six.second || three_five.second == five_six.second) swap(five_six.first, five_six.second);

	// Answer
	cout << "! " << one_two.first << ' ' << one_two.second << ' ' << three_four.first << ' ' << three_four.second << ' ' << five_six.first << ' ' << five_six.second << endl;
}