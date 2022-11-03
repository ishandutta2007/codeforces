#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int t[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		t[a]++ , t[b]++;
	}

	int x = 0;
	for(int i = 0; i < n; i++)
		if(t[i] > 2)
			x++;

	if(x > 1)
		return cout << "No" << endl , 0;
	
	cout << "Yes" << endl;
	
	int node = 0;
	for(int i = 0; i < n; i++)
		if(t[i] > 2)
			node = i;

	cout << t[node] << endl;
	for(int i = 0; i < n; i++)
		if(t[i] == 1 && i != node)
			cout << i + 1 << " " << node + 1 << endl;
}