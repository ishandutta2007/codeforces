#include <bits/stdc++.h>
using namespace std;
int main () {
	#define int long long
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	vector <int> A, B;
	for(int i = 0; i < n; i++)
	{
		if(s1[i] == 'a' && s2[i] == 'b')
		{
			A.push_back(i);
		}
		else if(s1[i] == 'b' && s2[i] == 'a')
		{
			B.push_back(i);
		}
	}
	if(A.size() % 2 == B.size() % 2)
	{
		cout << (A.size() + B.size()) / 2 + (A.size() % 2) << "\n";
		for(int i = 0; i + 1 < A.size(); i += 2)
		{
			s1[A[i]] = 'b';
			s2[A[i + 1]] = 'a';
			cout << A[i] + 1 << " " << A[i + 1] + 1 << "\n";
		}
		for(int i = 0; i + 1 < B.size(); i+= 2)
		{
			s1[B[i]] = 'a';
			s2[B[i + 1]] = 'b';
			cout << B[i] + 1 << " " << B[i + 1] + 1 << "\n";
		}
		if(A.size() % 2)
		{
			cout << A[A.size() - 1] + 1 << " " << A[A.size() - 1] + 1 << "\n";
			cout << A[A.size() - 1] + 1 << " " << B[B.size() - 1] + 1;
		}
	}
	else
	{
		cout << -1;
	}
	return 0;
}