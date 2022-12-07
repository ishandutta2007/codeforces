#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
 	cin >> n;
 	for(int i = 1; i <= n; i ++)
 	{
	 	if(i % 2 == 1) printf("I hate");
	 	if(i % 2 == 0) printf("I love");
 		if(i == n) printf(" it");
 		else printf(" that ");

	 	
 	}
	return 0;
 }