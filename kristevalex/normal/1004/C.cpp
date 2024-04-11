#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)





long long n, m = 0, k, ans = 0;



vector <long long> Left(100000, -1);
vector <long long> Right(100000, 1000000);

int main()
    {
    FAST;

    cin >> n;

    vector<long long> data (n);


    for (int i = 0; i < n; i++)
        {
        cin >> data[i];
        data[i]--;

        }

    for (int i = 0; i < n; i++)
        {
        if (Left[data[i]] == -1) Left[data[i]] = i;
        }

    for (int i = n-1; i >= 0; i--)
        {
        if (Right[data[i]] == 1000000) {Right[data[i]] = i; m++;}
        }

    sort(Left.begin(), Left.end());
    sort(Right.begin(), Right.end());

    int r = 0, l = 0;

    bool end_ = false;

    while (r < 100000)
        {
        while (Right[r] > Left[l])
            {
            l++;
            if (l == 100000)
                {
                end_ = true;
                break;
                }
            }

        if (end_) break;

        ans+= (100000-l);

        //cout << ans << endl;

        r++;
        }


    cout << m*m - ans;

    return 0;
    }