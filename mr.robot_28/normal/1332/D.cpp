#include <bits/stdc++.h>
using namespace std;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> k;
	int r = 1;
	while(r <= k)
	{
		r = r * 2;
	}
	r = r * 2;
	r--;
	vector <vector <int> > A(3, vector <int> (3, 0));
	A[0][0] = r;
	A[1][0] = r - k;
	A[0][1] = k;
	A[1][1] = r;
	A[1][2] = k;
	A[2][1] = k;
	A[2][2] = k;
	cout << 3 << " " << 3 << "\n";
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
    return 0;
}