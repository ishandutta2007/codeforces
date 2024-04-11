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

ll n, k;

int main()
{
	cin >> n >> k;
	if (n / k % 2) printf("YES\n");
	else printf("NO\n");
	return 0;
}