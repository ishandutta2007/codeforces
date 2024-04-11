#pragma gcc optimize("O3");
#pragma gcc target("SSE4");
#include <bits/stdc++.h> 
using namespace std;
const int inf = 1e9;
int main()
{
	int n, m, k, imin = 0, count = 0, o= -1;
	cin >> n >> m >> k;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	set <int> W;
	set <int> :: iterator it;
	for(int i = 0; i < A.size(); i++)
	{
		if(W.size() < k - 1)
		{
			W.insert(A[i]);
			it = W.begin();
			o = A[i];
		}
		else if(W.size() == 0 && k == 1)
		{
			count++;
		}
		else
		{
			while(o - *it >= m)
			{
				//cout << *W.end() << " " << *it << " ";
				W.erase(*it);
				it = W.begin();
			}
		   // cout << i << " " << W.size() << " " << *it;
			if(A[i] - *it < m && W.size() >= k - 1)
			{
				count++;
			//	cout << A[i];
			}
			else
			{
				W.insert(A[i]);
				o = A[i];
			}
		}
	}
	cout << count;
	return 0;
}