#include<bits/stdc++.h> 
#include<fstream>
using namespace std;
#define int long long
main () {
	int n;
	cin >> n;
	int cnt1 = 0, cnt2 = 0;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		if(i % 2 == 0)
		{
			cnt1 += A[i] / 2;
			cnt2 += (A[i] + 1) / 2;
		}
		else
		{
			cnt1 += (A[i] + 1) / 2;
			cnt2 += A[i] / 2;
		}
	}
	cout << min(cnt1, cnt2);
    return 0;
}