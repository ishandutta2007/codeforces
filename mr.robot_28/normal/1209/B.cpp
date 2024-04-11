#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector <pair <int, int> > A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first >> A[i].second;
	}
	int max = 0;
	for(int i = 0; i <= 1000000; i++)
	{
		int cnt = 0;
		for(int j = 0; j < n; j++)
		{
			if(i >= A[j].second && ((i - A[j].second) / A[j].first + 1) % 2 != s[j] - '0')
			{
				cnt++;
			}
			else if(i < A[j].second && s[j] -'0' == 1)
			{
				cnt++;
			}
		}
		if(cnt > max)
		{
			max = cnt;
		}
	}
	cout << max;
    return 0;
}