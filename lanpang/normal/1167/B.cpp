#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;
const double eps = 1e-9;

int a[10] = {0,4,8,15,16,23,42} , c[10] , x , y;

int main()
{
	int i , j , k;
	cout << "? 1 2" << endl;
	cin >> x;
	cout << "? 2 3" << endl;
	cin >> y;
	for (i = 1 ; i <= 6 ; i++)
		for (j = 1 ; j <= 6 ; j++)
			for (k = 1 ; k <= 6 ; k++)
				if (a[i]*a[j] == x && a[j]*a[k] == y && i != j && j != k && i != k)
				{
					c[1] = a[i];
					c[2] = a[j];
					c[3] = a[k];
					break;
				}
	cout << "? 4 5" << endl;
	cin >> x;
	cout << "? 5 6" << endl;
	cin >> y;
	for (i = 1 ; i <= 6 ; i++)
		for (j = 1 ; j <= 6 ; j++)
			for (k = 1 ; k <= 6 ; k++)
				if (a[i]*a[j] == x && a[j]*a[k] == y && i != j && j != k && i != k)
				{
					c[4] = a[i];
					c[5] = a[j];
					c[6] = a[k];
					break;
				}
	cout << "! " << c[1] << " " << c[2] << " " << c[3] << " " << c[4] << " " << c[5] << " " << c[6] << endl; 
	return 0;
}