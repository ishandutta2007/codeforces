#include <bits/stdc++.h>
using namespace std;

//vector<vector<long>> dynamic;
//vector<long> c, s;

int main()
    {

	long N;
	cin >> N;


	vector<long> s(N);
	for (auto &x : s)
		{
        cin >> x;
		}

	vector<vector<long>> dynamic(N, vector<long>(3, LONG_MAX));

	vector<long> c(N);
	for (long i = 0; i < N; ++i)
	    {
		cin >> c[i];

		dynamic[i][0] = c[i];
	    }

	for (long i = 1; i < N; i++)
	    {
        for (long j = 0; j < i; j++)
            {
            if (s[j] < s[i] && dynamic[j][0] < LONG_MAX)
                {
                dynamic[i][1] = min(dynamic[i][1], c[i]+dynamic[j][0]);
                }
            }
	    }

    long ans = LONG_MAX;

    for (long i = 2; i < N; i++)
	    {
        for (long j = 1; j < i; j++)
            {
            if (s[j] < s[i] && dynamic[j][1] < LONG_MAX)
                {
                dynamic[i][2] = min(dynamic[i][2], c[i]+dynamic[j][1]);
                }
            }
        ans = min(dynamic[i][2], ans);
	    }

    cout << ((ans == LONG_MAX)? -1:ans);


	return 0;
    }