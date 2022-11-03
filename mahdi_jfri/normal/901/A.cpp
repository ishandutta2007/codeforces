#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int a[maxn];

int main()
{
	int h;
	cin >> h;
	for(int i = 0; i <= h; i++)
		cin >> a[i];
	int k = -1;
	for(int i = 0; i < h; i++)
		if(a[i] > 1 && a[i + 1] > 1)
			k = i;
	if(k == -1)
	{
		cout << "perfect" << endl;
		return 0;
	}
	cout << "ambiguous" << endl;
	cout << 0 << " ";
	int par = 1 , t = 0;
	for(int i = 1; i <= h; i++)
	{
		for(int j = 0; j < a[i]; j++)
			cout << par << " ";
		par += a[i];
	}
	cout << endl << 0 << " ";
	par = 1;
	for(int i = 1; i <= h; i++)
	{
		int x = 0;
		if(i == k + 1)
		{
			cout << par - 1 << " ";
			x = 1;
		}
		for(int j = x; j < a[i]; j++)
			cout << par << " ";
		par += a[i];
	}
	cout << endl;
}