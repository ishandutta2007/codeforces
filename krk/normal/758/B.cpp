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

const int Maxd = 4;

string s;
int dead[Maxd];
int my[Maxd]; // r, b, y, g

int main() 
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'R') my[0] = i % 4;
		else if (s[i] == 'B') my[1] = i % 4;
		else if (s[i] == 'Y') my[2] = i % 4;
		else if (s[i] == 'G') my[3] = i % 4;
		else dead[i % 4]++;
	for (int i = 0; i < 4; i++)
		printf("%d%c", dead[my[i]], i + 1 < 4? ' ': '\n');
    return 0;
}