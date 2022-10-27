#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 2e6;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cno;
    cin >> cno;
    while(cno--)
    {
        string s;
        cin >> s;
        int n = sz(s);
        if(n == 1)
        {
            cout << s << "\n";
            continue;
        }
        int mina = 1e9;
        vector <int> cnt(26, 0);
        for(int i = 0; i < n; i++)
        {
            cnt[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(cnt[i] > 0)
            {
                mina = min(mina, cnt[i]);
            }
        }
        char t;
        if(mina == 1)
        {
            for(int i = 0; i < 26; i++)
            {
                if(cnt[i] == 1)
                {
                    t = i + 'a';
                    cnt[i]--;
                    break;
                }
            }
            cout << t;
            for(int i = 0; i < 26; i++){
                while(cnt[i] > 0)
                {
                    t = 'a' + i;
                    cout << t;
                    cnt[i]--;
                }
            }
            cout << "\n";
            continue;
        }
        int imin = -1;
        for(int i = 0; i < 26; i++)
        {
            if(cnt[i] > 0)
            {
                imin = i;
                break;
            }
        }
        if(cnt[imin] <= 1 + (n) / 2)
        {
            bool fl = 0;
            t = 'a' + imin;
            cout << t;
            cnt[imin]--;
            for(int i = 1; i < n; i++)
            {
                if(fl)
                {
                    for(int j = imin + 1; j < 26; j++)
                    {
                        if(cnt[j] > 0)
                        {
                            cnt[j]--;
                            t = 'a' + j;
                            cout << t;
                            break;
                        }
                    }
                    fl = 0;
                }
                else
                {
                    for(int j = 0; j < 26; j++)
                    {
                        if(cnt[j] > 0)
                        {
                            cnt[j]--;
                            if(j == imin)
                            {
                                fl = 1;
                            }
                            t = 'a' + j;
                            cout << t;
                            break;
                        }
                    }
                }
            }
            cout << "\n";
            continue;
        }
        if(cnt[imin] == n)
        {
            cout << s << "\n";
            continue;
        }
        t = 'a' + imin;
        cout << t;
        cnt[imin]--;
        int imin1 ;
        for(int i = 0; i < 26; i++)
        {
            if(i != imin && cnt[i] >0)
            {
                imin1 = i;
                t = 'a' + i;
                cout << t;
                cnt[i]--;
                break;
            }
        }
        bool fl = 0;
        for(int i = 0; i < 26; i++)
        {
            if(cnt[i] > 0 &&i != imin &&i != imin1)
            {
                fl = 1;
                t = 'a' + i;
                break;
            }
        }
        if(fl)
        {
            while(cnt[imin] > 0)
            {
                char t1 = 'a' + imin;
                cout << t1;
                cnt[imin]--;
            }
            cout << t;
            cnt[t - 'a']--;
            for(int i = 0; i < 26; i++)
            {
                while(cnt[i] > 0)
                {
                    t = 'a' + i;
                    cout << t;
                    cnt[i]--;
                }
            } 
        }
        else
        {
            for(int i = 0; i < 26; i++)
            {
                while(i != imin && cnt[i] > 0)
                {
                    cnt[i]--;
                    t = 'a' + i;
                    cout << t;
                }
            }
            while(cnt[imin] > 0)
            {
                t = 'a' + imin;
                cnt[imin]--;
                cout << t;
            }
        }
        cout << "\n";
    }
    return 0;
}