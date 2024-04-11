#include <bits/stdc++.h>

using namespace std;
int main()
{
	#define int long long
    int n, k;
    cin >> n >> k;
    vector <pair <int, int> > A(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> A[i].first >> A[i].second;
    	swap(A[i].first, A[i].second);
	}
	sort(A.begin(), A.end());
	multiset <int> K;
	int sum = 0;
	int max = 0, min = 1e9;
	for(int i = A.size() - 1; i >= 0; i--)
	{
		if(K.size() == k)
		{
			multiset<int> :: iterator it;
			it = K.begin();
			if(*it < A[i].second)
			{
				sum += A[i].second - *it;
				K.erase(it);
				K.insert(A[i].second);
				min = A[i].first;
				if(sum * A[i].first > max)
				{
					max = sum * A[i].first;
				}
			}
		}
		else
		{
			min = A[i].first;
			sum += A[i].second;
			K.insert(A[i].second);
			if(sum * A[i].first > max)
			{
				max = sum * A[i].first;
			}
		}
	}
	cout << max;
	return 0;
}