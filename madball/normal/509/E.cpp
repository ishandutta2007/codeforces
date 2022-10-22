#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

bool vowel(char c) {
	for (int i = 0; i < 6; i++)
		if (c == "AEIOUY"[i])
			return true;
	return false;
}

int main() {
	string s;
	long long sum = 0;
	double res = 0;
	cin >> s;
	vector<long long> ssums(s.size());
	for (int i = 0; i < s.size(); i++) {
		sum += vowel(s[i]);
		ssums[i] = sum;
	}
	for (int i = 0; i < (s.size() + 1) / 2; i++) {
		if (i * 2 + 1 == s.size())
			res += sum * 1.0 / (i + 1);
		else
			res += sum * (1.0 / (i + 1) + 1.0 / (s.size() - i));
		sum += ssums[s.size() - i - 2] - ssums[i];
	}
	cout.precision(20);
	cout << res;
	return 0;
}