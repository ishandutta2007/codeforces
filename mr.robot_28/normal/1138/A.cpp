#include <iostream>
#include <cstdio>
#include<vector>
#include <cstring>
using namespace std;
int main()
{
	#define int long long
    int n;
    cin >> n;
    vector <int> A(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> A[i];
	}
	vector <int> K;
	int cnt = 0, cnt1 = 0;
	for(int i = 0; i < n; i++)
	{
		if(i == 0 || A[i - 1] != A[i])
		{
			K.push_back(cnt1);
			cnt1 = 1;
		}
		else
		{
			cnt1++;
		}
	}
	K.push_back(cnt1);
	for(int i = 0; i < K.size() - 1; i++)
	{
		cnt = max(cnt,2 * min(K[i], K[i + 1]));
	}
	cout << cnt;
    return 0;
}