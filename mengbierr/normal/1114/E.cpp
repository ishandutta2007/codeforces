#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

int n,res,N,d;
int a[65];

bool mark[1000005];

int Rand()
{
	int res = 0;
	for (int i = 30;i >= 0;i--)
		res += ((rand() & 1) << i);
	return res;
}

int main()
{
	cin >> n;
	int low = 0,high = 1000000000,cnt = 0;
	while (low < high)
	{
		cnt++;
		int mid = (low + high) >> 1;
		cout << "> " << mid << endl;
		cout.flush();
		cin >> res;
		if (res)
			low = mid + 1;
		else
			high = mid;
	}
	srand(time(0));
	N = min(n,60 - cnt);
	for (int i = 1;i <= N;i++)
	{
		int p = Rand() % n + 1;
		while (mark[p])
			p = Rand() % n + 1;
		mark[p] = true;
		cout << "? " << p << endl;
		cout.flush();
		cin >> a[i];
	}
	sort(a + 1,a + N + 1);
	d = 0;
	for (int i = 1;i < N;i++)
		d = __gcd(d,a[i + 1] - a[i]);
	cout << "! " << low - (n - 1) * d << ' ' << d << endl;
	return 0;
}