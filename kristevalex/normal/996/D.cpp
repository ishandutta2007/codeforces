#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long n, ans = 0;

vector<long long> data;


long long move_first(int num)
    {
    long long curr = data[2*num];

    int i = 2*num+1;
    for ( ; i < 2*n+1; i++)
        {
        //if (i == 2*n) cout << "rhjkl;";
        if (curr == data[i]) break;
        }

    for (int j = i-1; j > 2*num; j--)
        {
        data[j+1] = data[j];
        }

    //cout << num << " " << i << endl;

    return -2*num + i - 1;
    }


int main()
    {
    FAST;

    cin >> n;

    data.resize(2*n);


    for (int i = 0; i < 2*n; i++)
        {
        cin >> data[i];
        }

    for (int i = 0; i < n; i++)
        {
        ans+= move_first(i);
        }

    cout << ans;

    return 0;
    }