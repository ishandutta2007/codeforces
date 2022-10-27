#include<bits/stdc++.h> 
using namespace std;
int main () { 
#define int long long
	int n, m;
	cin >> n >> m;
	vector <long long> A(n), B(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	set<pair <int, int> > W;
	for(int j = 0; j < n; j++)
	{
		cin >> B[j];
		W.insert({B[j], j});
	}
	for(int i = 0; i < m; i++)
	{
		int t, ind;
		cin >> ind >> t;
		ind--;
		int count =0;
		if(A[ind] != 0)
		{
			count += B[ind] * min(A[ind], t);
			int min1 = min(t, A[ind]);
			t -= min1;
			A[ind] -= min1;
			if(A[ind] == 0)
			{
				W.erase({B[ind], ind});
			}
		}
		set <pair <int, int> > :: iterator it;
		while(t > 0 && W.size() > 0)
		{
			it = W.begin();
			pair <int, int> k = *it;
			W.erase(k);
			int min1 = min(t, A[k.second]);
			count += min1 * k.first;
			t -= min1;
			A[k.second] -= min1;
			if(A[k.second] != 0)
			{
				W.insert({B[k.second], k.second});
			}
		}
		if(t > 0)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << count << endl;
		}
	}
	return 0;
}