#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector <double> A(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> A[i];
	}
	vector <int> B(n);
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		B[i] = floor(A[i]);
		sum += B[i];
	}
	for(int i = 0; i < n; i++){
		if(sum != 0 && B[i] + 1 - A[i] < 1)
		{
			B[i]++;
			sum++;
		}
		cout << B[i] << endl;
	}
    return 0;
}