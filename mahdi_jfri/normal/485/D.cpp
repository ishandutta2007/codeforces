#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e6 + 20;
int a[maxn] , res , mx[maxn];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d" , &a[i]) , mx[a[i]] = a[i];
	n = unique(a , a + n)-a;
	sort(a , a + n);
	for(int i = 1; i <= 1e6; i++)
		mx[i] = max(mx[i - 1] , mx[i]);
	for(int i = n - 1; a[i] > res; i--)
	{
		for(int j = 1; j * a[i] <= 1e6; j++)
			res = max(res , mx[min((j + 1) * a[i] - 1 , 1000000)] % a[i]);
	}
	cout << res;
}