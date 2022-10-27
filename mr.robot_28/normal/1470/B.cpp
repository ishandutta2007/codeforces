#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6 + 10;
int pr[M];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1;i <= M; i++)
    {
        pr[i] = i;
    }
    for(int i = 2; i <= M; i++)
    {
        if(pr[i] == i)
        {
            int j =i * 2;
            while(j <= M)
            {
                pr[j] = i;
                j += i;
            }
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> a(n);
        map <int, int> mp;
        map <int, int> mp2;
        int ans1 = 0;
        int ans2 = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            int w = 1;
            while(a[i] > 1)
            {
                int t = pr[a[i]];
                int c =0;
                while(a[i] % t == 0)
                {
                    a[i] = a[i] / t;
                    c++;
                }
                c = c % 2;
                if(c == 1)
                {
                    w = w * t;
                }
            }
            a[i] = w;
            mp[a[i]]++;
            ans1 = max(ans1, mp[w]);
        }
        map <int, int> :: iterator it;
        for(it = mp.begin(); it != mp.end(); it++)
        {
            if(it -> second % 2 == 0)
            {
                mp2[1] += it -> second;
            }
            else
            {
                mp2[it -> first] += it -> second;
            }
        }
        for(it = mp2.begin(); it != mp2.end(); it++)
        {
            ans2 = max(ans2, it -> second);
        }
        int q;
        cin >> q;
        while(q--)
        {
            int w;
            cin >> w;
            if(w == 0)
            {
                cout << ans1 << "\n";
            }
            else
            {
                cout << ans2 << "\n";
            }
        }
    }
    return 0;
}