#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxd = 10;

string A, B;
int has[Maxd];
string res;

void Create(int from)
{
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < has[i]; j++)
			res[from++] = i + '0';
}

int main()
{
	cin >> A;
	cin >> B;
	int st = 0;
	for (int i = 0; i < A.length(); i++)
		has[A[i] - '0']++;
	while (A.length() < B.length()) { A = "0" + A; st++; }
	res = A;
	for (int i = st; i < A.length(); i++)
		for (int j = Maxd - 1; j >= 0; j--) if (has[j] > 0) {
			has[j]--;
			res[i] = j + '0';
			Create(i + 1);
			if (res <= B) break;
			has[j]++;
		}
	int pos = 0;
	while (res[pos] == '0') pos++;
	cout << res.substr(pos) << endl;
	return 0;
}