#include<bits/stdc++.h>
using namespace std;
vector <int> A;
vector <int> Pow(30);
inline int build(int i, int l, int r)
{
	int l1 = l - 1, r1 = r + 1;
	while(r1 - l1 > 1)
	{
		int midd = (r1 + l1) / 2;
		int k = Pow[i];
		if((A[midd] & k))
		{
			r1 = midd;
		}
		else
		{
			l1 = midd;
		}
	}
	if(l1 == l - 1 || l1 == r)
	{
		if(i == 0)
		{
			return 0;
		}
		else
		{
			return build(i - 1, l, r);
		}
	}
	if(i == 0)
	{
		return 1;
	}
	int rez1 = build(i - 1, l, l1);
	int rez2 = build(i - 1, l1 + 1, r);
	return min(rez1, rez2) + Pow[i]; 
}
signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	cout.tie(NULL);
  	int n;
  	cin >> n;
  	A.resize(n);
  	Pow[0] = 1;
  	for(int i = 1; i <= 29; i++)
  	{
  		Pow[i] = Pow[i - 1] * 2;
  	}
  	for(int i = 0; i < n; i++)
  	{
  		cin >> A[i];
  	}
  	sort(A.begin(), A.end());
  	int rez = build(29, 0, n - 1);
  	cout << rez;
    return 0;
}