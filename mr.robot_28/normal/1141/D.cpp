#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector <vector<int> > A(26), B(26);
    int l = 0, r = 0;
    vector <int> L, R;
    for(int i = 0; i < n; i++)
    {
    	if(a[i] == '?')
    	{
    		l++;
    		L.push_back(i);
		}
		else
		{
			A[a[i] - 'a'].push_back(i);
		}
		if(b[i] == '?')
		{
			R.push_back(i);
			r++;
		}
		else
		{
			B[b[i] - 'a'].push_back(i);
		}
	}
	int count = 0;
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < 26; i++)
	{
		count += min(A[i].size(), B[i].size());
		sum1 += A[i].size() - min(A[i].size(), B[i].size());
		sum2 += B[i].size() - min(A[i].size(), B[i].size());
	}
	count += min(sum1, r);
	r = r - min(sum1, r);
	count += min(sum2, l);
	l = l - min(sum2, l);
	cout << count + min(l, r) << endl;
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < min(A[i].size(), B[i].size()); j++)
		{
			cout << A[i][j] + 1 << " " << B[i][j] + 1 << endl;
		}
	}
	if(L.size() != 0)
	{
	for(int i = 0; i < 26; i++)
	{
		for(int j = min(A[i].size(), B[i].size()); j < B[i].size(); j++)
		{
			cout << L[0] + 1 << " " << B[i][j] + 1 << endl;
			L.erase(L.begin() + 0);
			if(L.size() == 0)
			{
				break;
			}
		}
		if(L.size() == 0)
		{
			break;
		}
	}
	}
	if(R.size() != 0)
	{
	for(int i = 0; i < 26; i++)
	{
		for(int j = min(A[i].size(), B[i].size()); j < A[i].size(); j++)
		{
			cout << A[i][j] + 1 << " " << R[0] + 1 << endl;
			R.erase(R.begin());
			if(R.size() == 0)
			{
				break;
			}
		}
		if(R.size() == 0)
		{
			break;
		}
	}
	}
	for(int j = 0; j < min(R.size(), L.size()); j++)
	{
		cout << L[j] + 1 << " " << R[j] + 1 << endl; 
	}
    return 0;
}