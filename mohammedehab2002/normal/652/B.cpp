#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main()
{
	int n,i=0;
	cin >> n;
	deque <long long> d(n);
	for (i=0;i<n;i++)
	cin >> d[i];
	sort(d.begin(),d.end());
	for (i=0;i<n/2;i++)
	cout << d[i] << ' ' << d[n-i-1] << ' ';
	if (n%2)
	cout << d[n/2];
}