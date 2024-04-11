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

int main() 
{
	cin >> a;
	cin >> b;
	if (a == b) printf("-1\n");
	else printf("%d\n", max(int(a.length()), int(b.length())));
    return 0;
}