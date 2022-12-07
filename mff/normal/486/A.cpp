#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <utility>
using namespace std;

typedef long long int64;

int main()
{
	int64 n;
	cin >> n;
	if (n % 2 == 0)
		cout << n/2 << endl;
	else
		cout << -(n+1)/2 << endl;
	return 0;
}