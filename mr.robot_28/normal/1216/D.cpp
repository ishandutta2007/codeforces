
#include<bits/stdc++.h>
 
using namespace std;
signed main(){
	#define int long long
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int nod = 0;
	int sum = 0;
	for(int i = 0; i < n - 1; i++)
	{
		sum += (A[n - 1] - A[i]);
		nod = __gcd(nod, A[n - 1] - A[i]);
	}
	if(sum == 0)
	{
		cout << 0 << " "  << 0;
	}
	else
	{
		cout << sum / nod << " " << nod;
	}
	return 0;
}