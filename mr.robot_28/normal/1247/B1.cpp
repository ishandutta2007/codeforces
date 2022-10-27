#include<bits/stdc++.h>
using namespace std;
vector <int> used(100);
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k, d;
		cin >> n >> k >> d;
		vector <int> A(n);
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		for(int i = 0; i < k; i++){
			used[i] = 0;
		}
		int cnt = 0;
		for(int i = 0; i < d; i++){
			if(used[A[i] - 1] == 0)
			{
				cnt++;
			}
			used[A[i] - 1]++;
		}
		int min = cnt;
		for(int i = d; i < n; i++)
		{
			if(used[A[i] - 1] == 0)
			{
				cnt++;
			}
			used[A[i] - 1]++;
			if(used[A[i - d] - 1] == 1)
			{
				cnt--;
			}
			used[A[i - d] - 1]--;
			if(cnt < min)
			{
				min = cnt;
			}
		}
		cout << min << "\n";
	}
	return 0;
}