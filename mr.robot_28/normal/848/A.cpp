#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> k;
	if(k == 0)
	{
		cout << "a";
		return 0;
	}
	vector <int> mass;
	while(k > 0){
		int t = sqrt(k);
		while(t * (t - 1) < 2 * k)
		{
			t++;
		}
		while(t * (t - 1) > 2 * k)
		{
			t--;
		}
		mass.push_back(t);
		k -= t * (t - 1) / 2;
	}
	for(int i = 0; i < mass.size(); i++)
	{
		char t = 'a' + i;
		while(mass[i] > 0)
		{
			cout << t;
			mass[i]--;
		}
	}
    return 0;
}