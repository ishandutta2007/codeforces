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
	int n;
	cin >> n;
	vector <int> A(26, 0);
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		A[s[0] - 'a'] ++;
	}
	int sum = 0;
	for(int i = 0; i < 26; i++)
	{
		int t = A[i] / 2;
		sum += t * (t - 1)  / 2;
		sum += (A[i] - t) * (A[i] - t - 1) / 2;
	}
	cout << sum;
    return 0;
}