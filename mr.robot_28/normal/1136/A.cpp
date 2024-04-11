#include<bits/stdc++.h> 

using namespace std; 

int main() { 
	int n;
	cin >> n;
	vector <pair <int, int> > A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first >> A[i].second;
	}
	int k;
	cin >> k;
	for(int i = 0; i < n; i++)
	{
		if(k >= A[i].first && k <=A[i].second)
		{
			cout << n - i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}