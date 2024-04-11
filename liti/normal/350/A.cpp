#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100000];
int b[100000];
int main()
{
	int n , m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int j = 0; j < m; j++)
		cin >> b[j];
	sort(b , b + m);
	sort(a , a + n);
	int v = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(a[i] > b[j]) {
				cout << "-1" << endl;
				return 0;
			}
	int ans = max(a[0] * 2 , a[n - 1]);
	if(ans >= b[0])
		cout << "-1" << endl;
	else
		cout << ans << endl;
	return 0;
}