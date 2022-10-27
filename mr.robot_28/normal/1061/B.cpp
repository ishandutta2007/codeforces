#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b )
{
	return a > b;
}
int main(){
	#define int long long
	int n, m;
	cin >> n >> m;
	vector <int> A(n);
	int j = 0, cnt = 0;
	for(int i = 0; i < A.size(); i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end(), cmp);
	int sum = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if(A[i + 1] >= A[i] && A[i] != 1)
		{
			sum += A[i + 1];
			A[i + 1] = A[i] - 1;
		}
		else if(A[i + 1] >= A[i])
		{
			sum += A[i + 1] - 1;
			A[i + 1] = 1;
		}
		else
		{
			sum += min(A[i] - 1, A[i + 1]);
		}
	}
	cout << sum;
	return 0;
}