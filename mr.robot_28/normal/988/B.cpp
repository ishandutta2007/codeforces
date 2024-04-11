#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(string a, string b)
{
	return a.size() < b.size();
}
int main()
{
	int n;
	cin >> n;
	vector <string > A(n);
	for(int i = 0; i < n; i ++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end(), cmp);
	bool e = true;
	for(int i = 0 ; i < n - 1; i++)
	{
		int k = A[i + 1].find(A[i]);
		if(k < 0 )
		{
			e = false;
		}
	}
	if(e)
	{
		cout << "YES" << endl;
		for(int i = 0; i < n; i++)
		{
			cout << A[i] << endl;
		}
	}
	else
	{
		cout << "NO";
	}
    return 0;
}