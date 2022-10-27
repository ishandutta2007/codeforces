#include<bits/stdc++.h> 
using namespace std;
int main () {
	int n, m, k;
	cin >> n >> m >> k;
	vector <int> A(n);
	multiset <int> L;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		if(i != 0)
		{
			L.insert(A[i] - A[i - 1]);
		}
	}
	int sum = n, count = n;
	set <int> :: iterator it;
	for(it = L.begin(); it != L.end(); it++)
	{
		if(count > k)
		{
			//cout << *it << " " << count << endl;
			sum += *it - 1;
			count--;
		}
		else
		{
			break;
		}
	}
	cout << sum;
	return 0;
}