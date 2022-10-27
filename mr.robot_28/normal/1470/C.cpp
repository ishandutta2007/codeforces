#include<bits/stdc++.h>
using namespace std;

int query(int x)
{
    int a;
    cout << "? " << x << endl;
    cin >> a;
    fflush(stdout);
    return a;
}
signed main()
{
  //  ios_base::sync_with_stdio(0);
//    cin.tie(0);
    //cout.tie(0);
    int n, k;
    cin >> n >> k;
    query(n);
    if(n == 5)
    {
        query(n);
        for(int i = 1; i <= n; i++)
        {
            int a = query(i);
            if(a == k)
            {
                cout <<"! " << i << endl;
                fflush(stdout);
                return 0;
            }
            query(i);
        }
        return 0;
    }
    int st = n - 1;
    int t = 1;
    while(st > 0)
    {
        int a = query(st);
        if(a < k)
        {
            break;
        }
        t++;
        st -= t;
    }
    if(st <= 0)
    {
        st = n;
    }
    while(query(st) != k)
    {
        st++;
        if(st == n + 1)
        {
            st = 1;
        }
    }
    cout << "! " << st << endl;
    fflush(stdout);
    return 0;
}