#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

char str[100005];

int main()
{
	scanf("%s", str) ;
	
	int n = strlen(str), ans;
	if (n >= 2) {
		ans = (str[n - 2] - 48) * 10 + (str[n - 1] - 48);
	}
	else ans = str[0] - 48;
	
	if (ans % 4 == 0) cout << 4 << endl;
	else cout << 0 << endl; 
	return 0;
}