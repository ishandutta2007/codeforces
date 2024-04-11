 #include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int CONST = 1e9 + 7;
main() {
	int h, w;
	cin >> h >> w;
	vector <int> r(h), c(w);
	for(int i = 0; i < h; i++)
	{
		cin >> r[i];
	}
	for(int i = 0; i < w; i++)
	{
		cin >> c[i];
	}
	vector <vector <int> > A(h, vector <int> (w, 0));
	int cnt = 1;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < r[i]; j++)
		{
			A[i][j] = 1;
		}
		if(r[i] != w)
		{
			A[i][r[i]] = -1;
		}
	}
	for(int j = 0; j < w; j++)
	{
		for(int i = 0; i < c[j]; i++)
		{
			if(A[i][j] == -1)
			{
				cout << 0;
				return 0;
			}
			A[i][j] = 1;
		}
		if(c[j] != h)
		{
			if(A[c[j]][j] != 1)
			{
				A[c[j]][j] = 1;
			}
			else
			{
				cout << 0;
				return 0;
			}
		}
	}
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			if(A[i][j] == 0)
			{
				cnt = (cnt * 2) % CONST;
			}
		}
	}
	cout << cnt;
   	return 0;
}