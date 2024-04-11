#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int *a = new int[n + 1];
	for (int i = 0; i < n; i++)cin >> a[i];
	a[n] = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			cout << "NO" << endl;
			return 0;
		}
		a[i] %= 2;
		if (a[i] == 1)
		{
			a[i]--;
			a[i + 1]--;
			continue;
		}
		else continue;
	}
	if(a[n]==0)cout << "YES" << endl;
	else cout << "NO" << endl;
    return 0;
}