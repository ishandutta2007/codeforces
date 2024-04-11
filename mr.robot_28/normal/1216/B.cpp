
#include<bits/stdc++.h>
 
using namespace std;
signed main(){
	int n;
	cin >> n;
	int sum = 0;
	vector <pair <int, int> > A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first;
		A[i].second = i + 1;
	}
	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());
	for(int i = 0; i < n; i++)
	{
		sum += (i * A[i].first + 1);
	}
	cout << sum << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << A[i].second << " ";
	}
	return 0;
}