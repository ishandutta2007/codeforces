#include<iostream>
#include <bits/stdc++.h> 
#include<vector>
#include<set>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <int> A(2 * n);
	for(int i = 0; i < 2 * n; i++){
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	vector <int> W(2750132);
	int i = 1, j = 2;
	for(j = 2; j <= 2750131;j++)
	{
		if(W[j] == 0)
		{
			W[j] = i;
			i++;
			int u = j * 2;
			while(u <= 2750131)
			{
				W[u] = -1;
				u += j;
			}
		}
	}
	vector <int> R;
	vector <bool> used(2 * n, false);
	for(int i = A.size() - 1; i>= 0; i--)
	{
		if(!used[i])
		{
			bool flag = W[A[i]] != -1;
			if(flag)
			{
				int l = 0, r = i;
				int k = W[A[i]];
				while(r - l > 1)
				{
					int midd = (r + l) / 2;
					if(A[midd] > k || A[midd] == k && used[midd] == true)
					{
						r = midd;
					}	
					else
					{
						l = midd;
					}
				}
				used[l] = true;
				R.push_back(k);
			}
			else
			{
				int t = A[i];
				for(int u = 2; u <= sqrt(A[i]); u++)
				{
					if(A[i] % u == 0)
					{
						t = t / u;
						break;
					}
				}
				int l = 0, r = i;
				while(r - l > 1)
				{
					int midd = (r + l) / 2;
					if(A[midd] > t || A[midd] == t && used[midd] == true)
					{
						r = midd;
					}
					else
					{
						l = midd;
					}
				}
				used[l] = true;
				R.push_back(A[i]);
			}
		}
	}
	for(int i = 0; i < R.size(); i++)
	{
		cout << R[i] << " ";
	}
	return 0;
}