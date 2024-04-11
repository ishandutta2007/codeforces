#include<bits/stdc++.h> 
using namespace std;

int main () {
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i =0; i < n; i++)
	{
		cin >> A[i];
	}
	int l = 0, r = 101;
	while(r - l > 2)
	{
		int l1 = (r - l) / 3 + l;
		int r1 = r - (r - l) / 3;
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < n; i++)
		{
			if(A[i] < l1)
			{
				cnt1 += l1 - A[i] - 1;
			}
			else if(A[i] > l1)
			{
				cnt1 += A[i] - l1 - 1;
			}
			if(A[i] < r1)
			{
				cnt2 += r1 - A[i] - 1;
			}
			else if(A[i] > r1)
			{
				cnt2 += A[i] - 1 - r1;
			}
		}
		if(cnt1 < cnt2)
		{
			r = r1;
		}
		else
		{
			l = l1;
		}
	}
	int midd = (r + l) / 2; 
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] < l)
		{
			cnt1 += l - A[i] - 1;
		}
		else if(A[i] > l)
		{
			cnt1 += A[i] - l - 1;
		}
		if(A[i] < r)
		{
			cnt2 += r - A[i] - 1;
		}
		else if(A[i] > r)
		{
			cnt2 += A[i] - 1 - r;
		}
		if(A[i] > midd)
		{
			cnt3 += A[i] - midd - 1;
		}
		else if(A[i] < midd)
		{
			cnt3 += midd - A[i] - 1;
		}
	}
	if(cnt1 <= cnt2 && cnt1 <= cnt3)
	{
		cout << l << " " << cnt1;
	}
	else if(cnt2 <= cnt3 && cnt2 <= cnt1)
	{
		cout << r << " " << cnt2;
	}
	else
	{
		cout << midd << " " << cnt3;
	}
	return 0;
}