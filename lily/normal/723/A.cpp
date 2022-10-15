#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

int a[3];

int main() {
	scanf("%d%d%d",a,a+1,a+2);
	sort(a,a+3);
	printf("%d\n",a[2]-a[0]);

	return 0;
}