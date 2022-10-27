#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <int> A(n);
	map<int,int> W; 
	bool f = true;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		W[A[i]]++;
		if(W[A[i]] >= 3)
		{
			f = false;
		}
	}
	if(f)
	{
		vector <int> K, L;
		cout << "YES" << endl;
		for(int i = 0; i < n; i++)
		{
			if(W[A[i]] == 2)
			{
				K.push_back(A[i]);
				L.push_back(A[i]);
				W[A[i]] = 3;
			}
			else if(W[A[i]] == 1)
			{
				K.push_back(A[i]);
			}
		}
		sort(K.begin(), K.end());
		sort(L.begin(), L.end());
		cout << K.size() << endl;
		for(int i = 0; i < K.size(); i++)
		{
			cout << K[i] << " ";
		}
		cout << endl;
		cout << L.size() << endl;
		for(int i = L.size() - 1; i>= 0; i--)
		{
			cout << L[i] << " ";
		}
	}
	else
	{
		cout << "NO";
	}
	return 0;
}