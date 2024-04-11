#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, q;
	cin >> n >> q;
	vector <int> A(n);
	vector <int> pred(n, -1);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	map <int, int> last;
	for(int i = n - 1; i >= 0; i--)
	{
		if(last.count(A[i]) != 0)
		{
			pred[i] = last[A[i]];
		}
		last[A[i]] = i;
	}
	vector <bool> used(n, false);
	int i = 0;
	int ans = n;
	while(i < n)
	{
		int j = i;
		int nxt = i;
		int max = 0;
		while(j <= nxt)
		{
			if(!used[j])
			{
				int u = j;
				int cnt = 1;
				while(pred[u] != -1)
				{
					cnt++;
					used[u] = true;
					u = pred[u];
				}
				if(u > nxt)
				{
					nxt = u;
				}
				if(cnt > max)
				{
					max = cnt;
				}
			}
			j++;
		}
		ans -= max;
		i = j;
	}
	cout << ans;
    return 0;
}