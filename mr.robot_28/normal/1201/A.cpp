#include<bits/stdc++.h>
using namespace std;
int main()
{
	#define int long long
	int n, m;
	cin >> n >> m;
	vector <string> s(n);
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	vector <int> A(m);
	for(int i = 0; i < m; i++)
	{
		cin >> A[i];
	}
	int sum = 0;
	for(int i = 0; i < m; i++)
	{
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0;
		for(int j = 0; j < n; j++)
		{
			if(s[j][i] == 'A')
			{
				cnt1++;
			}
			else if(s[j][i] == 'B')
			{
				cnt2++;
			}
			else if(s[j][i] == 'C')
			{
				cnt3++;
			}
			else if(s[j][i] == 'D')
			{
				cnt4++;
			}
			else
			{
				cnt5++;
			}
		}
		sum += A[i] * max(max(max(cnt1, cnt2), cnt3), max(cnt4, cnt5));
	}
	cout << sum;
	return 0;
}