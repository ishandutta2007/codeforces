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

const int Maxd = 7;
const char let[Maxd] = {'B', 'u', 'l', 'b', 'a', 's', 'r'};
const int tims[Maxd] = {1, 2, 1, 1, 2, 1, 1};

string s;
map <char, int> M;

int main() 
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		M[s[i]]++;
	int res = 100005;
	for (int i = 0; i < Maxd; i++)
		res = min(res, M[let[i]] / tims[i]);
	printf("%d\n", res);
    return 0;
}