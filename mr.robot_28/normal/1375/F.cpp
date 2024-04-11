#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	vector <int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	vector <pair <int, int> > ind(3);
	for(int i = 0; i < 3; i++)
	{
		ind[i] = {a[i], i};
	}
	sort(ind.begin(), ind.end());
	cout << "First" << endl;
	fflush(stdout);
	cout << ind[2].first * 2 - ind[1].first - ind[0].first << endl;
	fflush(stdout);
	int num;
	cin >> num;
	if(num == ind[1].second + 1)
	{
		cout << ind[2].first - ind[0].first << endl;
		fflush(stdout);
		int a;
		cin >> a;
	}
	else if(num == ind[0].second + 1)
	{
		cout << ind[2].first - ind[1].first << endl;
		fflush(stdout);
		int a;
		cin >> a;
	}
	else
	{
		a[ind[2].second] += ind[2].first * 2 - ind[1].first - ind[0].first;
		for(int i = 0; i < 3; i++){
			ind[i] = {a[i], i};
		}
		sort(ind.begin(), ind.end());
		cout << ind[2].first * 2 - ind[1].first - ind[0].first << endl;
		fflush(stdout);
		cin >> num;
		if(num == ind[1].second + 1)
		{
			cout << ind[2].first - ind[0].first << endl;
			fflush(stdout);
			int a;
			cin >> a;
		}
		else
		{
			cout << ind[2].first - ind[1].first <<endl;
			fflush(stdout);
			int a;
			cin >> a;
		}
	}
	return 0;
}