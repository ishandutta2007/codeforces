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

int x;

int main() 
{
	scanf("%d", &x);
	printf("%d\n", x / 5 + int(x % 5 > 0));
    return 0;
}