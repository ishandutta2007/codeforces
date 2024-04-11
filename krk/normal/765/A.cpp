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

int n;
string s;
int from, to;

int main() 
{
	cin >> n;
	cin >> s;
	while (n--) {
		string tmp; cin >> tmp;
		if (tmp.substr(0, 3) == s) from++;
		else if (tmp.substr(5, 3) == s) to++;
	}
	if (from > to) printf("contest\n");
	else printf("home\n");
    return 0;
}