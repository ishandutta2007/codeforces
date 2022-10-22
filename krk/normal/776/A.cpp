#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string a, b;
int n;

int main() 
{
	cin >> a >> b;
	cout << a << " " << b << endl;
	int n; scanf("%d", &n);
	while (n--) {
		string s1, s2; cin >> s1 >> s2;
		if (a == s1) a = s2;
		else if (b == s1) b = s2;
		cout << a << " " << b << endl;
	}
    return 0;
}