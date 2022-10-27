#include<iostream>
#include<cmath>
#include<map>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
main()
{
	#define int long long
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		A[i] = abs(A[i]);
	}
	sort(A.begin(), A.end());
	int r = 0, cnt = 0;
	for(int i = 0; i < n; i++)
	{
		while(r < A.size() && A[r] <= 2 * A[i])
		{
			r++;
		}
		cnt+= r - i - 1;
	}
	cout << cnt;
    return 0;
}