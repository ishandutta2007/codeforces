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

const int Maxl = 1000005;

char str[Maxl];
vector <char> S;
int res;

bool Ok(char a, char b)
{
	return a == '<' && b == '>' ||
		   a == '{' && b == '}' ||
		   a == '[' && b == ']' ||
		   a == '(' && b == ')';
}

int main() 
{
	scanf("%s", str);
	int n = strlen(str);
	for (int i = 0; i < n; i++)
		if (str[i] == '<' || str[i] == '{' || str[i] == '[' || str[i] == '(') S.push_back(str[i]);
		else if (S.empty()) { printf("Impossible\n"); return 0; }
			 else {
			 	res += !Ok(S.back(), str[i]);
			 	S.pop_back();
			 }
	if (!S.empty()) { printf("Impossible\n"); return 0; }
	printf("%d\n", res);
    return 0;
}