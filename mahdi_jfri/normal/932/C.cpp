#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , a , b;
	cin >> n >> a >> b;

	for(int i = 0; i * a <= n; i++)
		if((n - i * a) % b == 0)
		{
			int j = (n - i * a) / b;
			for(int k = 0; k < i; k++)
				for(int z = 0; z < a; z++)
					cout << ((z + 1) % a) + k * a + 1 << " ";
			for(int k = 0; k < j; k++)
				for(int z = 0; z < b; z++)
					cout << ((z + 1) % b) + i * a + k * b + 1 << " ";
			return 0;
		}
	cout << -1 << endl;
}