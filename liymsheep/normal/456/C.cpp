#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

typedef long long LL ;

LL f[100005];
LL arr[100005];
int main()
{	
	int n ;
    cin >> n;
    
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		arr[x]++;
	}
	
	for (int i = 1; i <= 100000; ++i) 
	{
		LL cost = arr[i] * i;
		if (i - 2 >= 0) cost += f[i - 2];
		f[i] = max(f[i - 1], cost);
	}

	cout << f[100000] << endl;
	return 0;
}