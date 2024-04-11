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

string s;
int cur;

int main() 
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (s[i] - 'a' == cur) cur++;
		else if (s[i] - 'a' > cur) { printf("NO\n"); return 0; }
	printf("YES\n");
    return 0;
}