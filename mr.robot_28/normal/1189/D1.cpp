#include<bits/stdc++.h> 
using namespace std;
int main () {
	int n;
	cin >> n;
	vector <pair <int, int > > A(n);
	vector <int> CNT(n);
	for(int i= 0; i < n - 1; i++)
	{
		cin >> A[i].first >> A[i].second;
		A[i].first--;
		A[i].second--;
		CNT[A[i].first]++;
		CNT[A[i].second]++;
	}
	for(int i = 0; i < n; i++)
	{
		if(CNT[i] == 2)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}