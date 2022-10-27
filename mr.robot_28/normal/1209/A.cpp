#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int cnt = 0;
	sort(A.begin(), A.end());
	vector <bool> used(n, false);
	for(int i = 0; i < n; i++){
		if(!used[i])
		{
			cnt++;
			for(int j = i; j < n; j++)
			{
				if(!used[j] && A[j] % A[i] == 0)
				{
					used[j] = true;
				}
			}
		}
	}
	cout << cnt;
    return 0;
}