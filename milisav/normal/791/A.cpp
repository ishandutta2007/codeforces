#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
using namespace std;
int a,b,k=0;
int main()
{
	scanf("%d %d",&a,&b);
	while(a<=b)
	{
		a=a*3;
		b=b*2;
		k++;
	}
	printf("%d",k);
	return 0;
}