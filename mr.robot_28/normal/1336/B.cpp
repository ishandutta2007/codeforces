#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> A, B, C;
int funct(int i, int j, int k)
{
	return ((A[i] - B[j]) * (A[i] - B[j]) + (A[i] - C[k]) * (A[i] - C[k]) + (B[j] - C[k]) * (B[j] - C[k]));
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		A.resize(a);
		B.resize(b);
		C.resize(c);
		for(int i = 0; i < a; i++)
		{
			cin >> A[i];
		}
		for(int i = 0; i < b; i++)
		{
			cin >> B[i];
		}
		for(int i = 0; i < c; i++)
		{
			cin >> C[i];
		}
		sort(A.begin(), A.end());
		sort(C.begin(), C.end());
		sort(B.begin(), B.end());
		int ans = 3e18;
		int iter1 = 0;
		int iter2 = 0;
		for(int i = 0; i < a; i++)
		{
			while(iter1 < b && B[iter1] <= A[i])
			{
				iter1++;
			}
			while(iter2 < c && C[iter2] < A[i])
			{
				iter2++;
			}
			if(iter1 != 0 && iter2 != c)
			{
				ans = min(ans, funct(i, iter1 - 1, iter2));
			}
		}
		iter1 = 0;
		iter2 = 0;
		for(int i = 0; i < a; i++)
		{
			while(iter1 < b && B[iter1] < A[i])
			{
				iter1++;
			}
			while(iter2 < c && C[iter2] <= A[i])
			{
				iter2++;
			}
			if(iter1 != b && iter2 != 0)
			{
				ans = min(ans, funct(i, iter1, iter2 - 1));
			}
		}
		iter1 = 0;
		iter2 = 0;
		for(int i = 0; i < b; i++)
		{
			while(iter1 < a && A[iter1] <= B[i])
			{
				iter1++;
			}
			while(iter2 < c && C[iter2] < B[i])
			{
				iter2++;
			}
			if(iter1 != 0 && iter2 != c)
			{
				ans = min(ans, funct(iter1 - 1, i, iter2));
			}
		}
		iter1 = 0;
		iter2 = 0;
		for(int i = 0; i < b; i++)
		{
			while(iter1 < a && A[iter1] < B[i])
			{
				iter1++;
			}
			while(iter2 < c && C[iter2] <= B[i])
			{
				iter2++;
			}
			if(iter1 != a && iter2 != 0)
			{
				ans = min(ans, funct(iter1, i, iter2 - 1));
			}
		}
		iter1 = 0;
		iter2 = 0;
		for(int i = 0; i < c; i++)
		{
			while(iter1 < a && A[iter1] <= C[i])
			{
				iter1++;
			}
			while(iter2 < b && B[iter2] < C[i])
			{
				iter2++;
			}
			if(iter1 != 0 && iter2 != b)
			{
				ans = min(ans, funct(iter1 - 1, iter2, i));
			}
		}
		iter1 = 0;
		iter2 = 0;
		for(int i = 0; i < c; i++)
		{
			while(iter1 < a && A[iter1] < C[i])
			{
				iter1++;
			}
			while(iter2 < b && B[iter2] <= C[i])
			{
				iter2++;
			}
			if(iter1 != a && iter2 != 0)
			{
				ans = min(ans, funct(iter1, iter2 - 1, i));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}