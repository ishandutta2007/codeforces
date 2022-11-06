#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <iomanip>
#include <queue>
#define ll long long
#define MAX_INT 922337203685477580LL
using namespace std;

int main() {
	int l[10] = {2,7,2,3,3,4,2,5,1,2};
	int n;
	cin >> n;
	int a = n/10;
	int b = n % 10;
	cout << l[a] * l[b] << endl;
	return 0;
}