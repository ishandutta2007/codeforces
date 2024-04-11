#include <bits/stdc++.h>
using namespace std;
signed main() {
	#define int long long
	int n, I;
	cin >> n >> I;
	I = I * 8;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	vector <pair <int, int> > CNT;
	sort(A.begin(), A.end());
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(i != 0 && A[i] != A[i -1])
		{
			CNT.push_back({A[i - 1], cnt});
			cnt = 1;
		}
		else
		{
			cnt++;
		}
	}
	CNT.push_back({A[n - 1], cnt});
	vector <int> pref(CNT.size()), post(CNT.size());
	for(int i = 0; i < CNT.size(); i++)
	{
		if(i == 0)
		{
			pref[i] = CNT[i].second;
		}
		else
		{
			pref[i] = pref[i - 1] + CNT[i].second;
		}
	}
	for(int i = CNT.size() - 1; i >= 0; i--)
	{
		if(i == CNT.size() - 1)
		{
			post[i] = CNT[i].second;
		}
		else
		{
			post[i] = post[i + 1] + CNT[i].second;
		}
	}
	int length = 0;
	int l = 0, r = n + 1;
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		int p = log2(midd);
		if(pow(2, p) < midd)
		{
			p++;
		}
		if(n * p <= I)
		{
			l = midd;
		}
		else
		{
			r = midd;
		}
	}
	length = l;
	int min = 1e9;
	for(int i = 0; i < CNT.size(); i++)
	{
		int sum = 0;
		if(i != 0)
		{
			sum += pref[i - 1];
		}
		if(i + length < CNT.size())
		{
			sum += post[i + length];
		}
		if(sum < min)
		{
			min = sum;
		}
	}
	cout << min;
    return 0;
}