#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, i, j;
	cin >> n >> m;
	vector<int> books(n);
	vector<int> days(m);
	for (i = 0; i < n; i++)
		cin >> books[i];
	for (i = 0; i < m; i++) {
		cin >> days[i];
		days[i]--;
	}

	vector<vector<int> > aamo(m + 1, vector<int>(n, 0));
	for (i = 1; i <= m; i++)
		for (j = 0; j < n; j++)
			aamo[i][j] = aamo[i - 1][j] + (days[i - 1] == j);
	//vector<long long> pres(m + 1);
	//pres[0] = 0;
	//for (i = 1; i <= m; i++)
	//	pres[i] = pres[i - 1] + books[days[i - 1]];

	vector<int> pos(n, -1);
	
	long long sum = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			if (aamo[i][j] > aamo[pos[days[i]] + 1][j])
				sum += books[j];
		//sum += pres[i] - pres[pos[days[i]] + 1];
		pos[days[i]] = i;
	}
	
	cout << sum;
	return 0;
}