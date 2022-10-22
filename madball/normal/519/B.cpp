#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/

	int n, i;
	cin >> n;
	vector<int> err1(n), err2(n - 1), err3(n - 2);
	for (i = 0; i < n; i++)
		cin >> err1[i];
	for (i = 0; i < n - 1; i++)
		cin >> err2[i];
	for (i = 0; i < n - 2; i++)
		cin >> err3[i];

	sort(err1.begin(), err1.end());
	sort(err2.begin(), err2.end());
	sort(err3.begin(), err3.end());

	for (i = 0; (i < n - 1) && (err1[i] == err2[i]); i++);
	cout << err1[i] << '\n';
	for (i = 0; (i < n - 2) && (err2[i] == err3[i]); i++);
	cout << err2[i];
	
	return 0;
}