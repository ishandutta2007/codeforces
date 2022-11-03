#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[maxn];
bool check(int l , int r)
{
	for(int i = l + 1; i <= r; i++)
		if(a[i] <= a[i - 1])
			return 0;
	return 1;
}
bool check2(int l , int r)
{
	for(int i = l + 1; i <= r; i++)
		if(a[i] != a[l])
			return 0;
	return 1;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
		{
			if(check(0 , i) && check2(i , j))
			{
				reverse(a + j , a + n);
				if(check(j , n - 1))
				{
					cout << "YES";
					return 0;
				}
				reverse(a + j , a + n);
			}
		}
	cout << "NO";
	return 0;
}