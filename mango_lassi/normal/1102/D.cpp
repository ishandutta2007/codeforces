#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

const int M = 3;
deque<int> inds[M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		inds[str[i]-'0'].push_back(i);
	}
	int tar = n / 3;

	// Ensure we have the correct amount of twos
	while(inds[2].size() < tar) {
		int j = -1;
		if (inds[1].size() <= tar) j = 0;
		else j = 1;

		int i = inds[j].back();
		str[i] = '2';
		inds[j].pop_back();
		inds[2].push_back(i);
	}
	sort(inds[2].begin(), inds[2].end());

	// Ensure we have the correct amount of zeroes
	while(inds[0].size() < tar) {
		int j = -1;
		if (inds[1].size() <= tar) j = 2;
		else j = 1;

		int i = inds[j].front();
		str[i] = '0';
		inds[j].pop_front();
		inds[0].push_back(i);
		
	}
	sort(inds[0].begin(), inds[0].end());

	// Ensure we have the correct amount of ones
	while(inds[1].size() < tar) {
		int j = 2;
		if (inds[0].size() <= tar) j = 2;
		else j = 0;

		if (j == 2) {
			int i = inds[j].front();
			str[i] = '1';
			inds[j].pop_front();
			inds[1].push_back(i);
		} else {
			int i = inds[j].back();
			str[i] = '1';
			inds[j].pop_back();
			inds[1].push_back(i);
		}
	}
	sort(inds[1].begin(), inds[1].end());

	cout << str << '\n';
}