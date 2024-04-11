#include <bits/stdc++.h>
                  
using namespace std;
#define int long long
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int f1 = 1;
	int f2 = 2;
	int cnt = 1;
	while(true)
	{
		int f3  = f1 + f2;
		f1 = f2;
		f2 = f3;
		if(f2 > n)
		{
			cout << cnt;
			return 0;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}