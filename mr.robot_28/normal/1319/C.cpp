#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> A(n);
    for(int i = 0; i < n; i++)
    {
        A[i] = s[i] - 'a';
    }
    int ans = 0;
    int cnt = 0;
    set <int> q;
    for(int i = 0; i < n; i++)
    {
        q.insert(-A[i]);
    }
    vector <bool> used(n);
    vector <bool> used1(n);
    while(q.size() != 0)
    {
        int v = -*q.begin();
        q.erase(q.begin());
        for(int i = 0; i < n; i++)
        {
            if(A[i] == v)
            {
                for(int j = i - 1; j >= 0; j--)
                {
                    if(!used[j])
                    {
                        if(A[j] + 1 == A[i])
                        {
                        used[i] = true;
                        ans++;
                        }
                        break;
                    }
                }
            }
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(A[i] == v && !used[i])
            {
                for(int j = i + 1; j < n; j++)
                {
                    if(!used[j])
                    {
                        if(A[j] + 1 == A[i])
                        {
                        used[i] = true;
                        ans++;
                        }
                        break;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}