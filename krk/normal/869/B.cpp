#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a, b;

int main()
{
	cin >> a >> b;
	ll lst = 1;
	for (ll i = a + 1; i <= b && lst != 0; i++)
		lst = lst * i % 10ll;
	cout << lst << endl;
	return 0;
}