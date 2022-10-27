#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s;
	cin >> n >> s;
	s -= n;
	if(s < n - 1 || s > n * (n - 1) / 2)
	{
		cout << "No";
		return 0;
	}
	int l = 1, r = n;
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		int s1 = 0;
		int r1 = 1;
		int sumh = 0;
		int p = 1;
		for(int i = 1; i < n; i++)
		{
			if(i >= r1)
			{
				s1++;
				r1 += p * midd;
				p = p * midd;
			}
			sumh += s1;
		}
		if(sumh > s)
		{
			l = midd;
		}
		else
		{
			r = midd;
		}
	}
	int k = r;
	vector <int> hcnt(n);
	vector <int> h(n);
	hcnt[0] = 1;
	int ost = n - 1;
	for(int i = 1; i < n; i++)
	{
		int l = 0, r = min(ost, hcnt[i - 1] * k) + 1;\
		while(r - l > 1){
			int midd = (r + l) / 2;
			int e = ost - midd;
			if(e * (2 * i + e + 1) / 2 + i * midd >= s)
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		hcnt[i] = l;
		s -= l * i;
		ost -= l;
	}
	int j = 0;
	for(int i = 0; i < n; i++)
	{
		if(hcnt[j] == 0){
			j++;
		}
		h[i] = j;
		hcnt[j]--;
	}
	cout << "Yes\n";
	vector <int> cnt1(n);
	j = 0;
	for(int i = 1; i < n; i++)
	{
		while(h[j] + 1 < h[i] || cnt1[j] == k)
		{
			j++;
		}
		cnt1[j]++;
		cout << j + 1 << " ";
	}
    return 0;
}