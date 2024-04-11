#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> l1(n);
	for(int i = 0; i < n; i++){
		cin >> l1[i];
	}
	string s;
	cin >> s;
	bool flag = false;
	int time = 0, stamina = 0, twicegrass = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == 'L')
		{
			time += l1[i];
			stamina -= l1[i];
			if(stamina < 0)
			{
				time -= stamina * (flag ? 3 : 5);
			stamina = 0;
			}
		}
		else if(s[i] == 'W')
		{
			flag = true;
			stamina += l1[i];
			time += 3 * l1[i];
		}
		else
		{
			stamina += l1[i];
			time += 5 * l1[i];
			twicegrass += 2 * l1[i];
		}
		twicegrass = min(twicegrass, stamina);
	}
	if (stamina > 0) {
        time -= (5-1) * twicegrass/2;

        time -= (3-1) * (stamina - twicegrass)/2;
    }
	cout << time;
	return 0;
}