#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n;
    ans = n-1;

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    int st = 0;
    set<int> base;
    while (st < n)
    {
        set<int> cur(base);
        for (int i = n; i >= st; --i)
            {
            ans = min(ans, (long long)(i - st));


            if(cur.find(data[i-1]) != cur.end())
                break;

            cur.insert(data[i-1]);
            }




        if(base.find(data[st]) != base.end())
            break;

        base.insert(data[st]);

        st++;

    }




    cout << ans;

    return 0;
    }


/*
9
1 1 2 3 4 5 6 1 1

*/