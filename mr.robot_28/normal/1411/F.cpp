#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int pow1[N];
int p[N];
int n;
int counter[N];
bool used[N];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    pow1[1] = 1;
    pow1[2] = 2;
    pow1[3] = 3;
    pow1[4] = 4;
    for(int i = 5; i < N; i++)
    {
        pow1[i] = pow1[i - 3] * 3 % mod;
    }
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < 6; i++)
        {
            counter[i] = 0;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
            counter[i] = 0;
            used[i] = 0;
        }
        counter[n] = 0;
        cout << pow1[n] << " ";
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(used[i])
            {
                continue;
            }
            int sz1 = 0;
            int st = i;
            while(true)
            {
                sz1++;
                used[st] = 1;
                st = p[st];
                if(st == i)
                {
                    break;
                }
            }
            if(sz1 >= 5)
            {
                int z = (sz1 - 2) / 3;
                ans += z;
                sz1 -= z * 3;
            }
            counter[sz1]++;
        }
        if(counter[4] > 1)
        {
            ans += counter[4] - 1;
            counter[1] += counter[4] - 1;
            counter[4] = 1;
        }
        if(n % 3 == 0 || n % 3 == 2)
        {
            if(counter[4])
            {
                ans += counter[4];
                counter[1] += counter[4];
                counter[4] = 0;
            }
            int t = min(counter[1], counter[2]);
            ans += t;
            counter[1] -= t;
            counter[2] -= t;
            if(counter[1])
            {
                int t= counter[1] / 3;
                ans += t * 2;
                counter[1] %= 3;
                if(counter[1] == 2)
                {
                    ans++;
                }
            }
            else
            {
                ans += (counter[2] / 3) * 3;
            }
            cout << ans << "\n";
            continue;
        }
        if(counter[4])
        {
            if(counter[1] < counter[2])
            {
                counter[2]--;
                counter[4]--;
                ans += 2;
            }
            else
            {
                int t= min(counter[1], counter[2]);
                counter[1] -= t;
                counter[2] -= t;
                ans += t;
                ans += counter[1] / 3 * 2 + counter[2] / 3 * 3;
                cout << ans << "\n";
                continue;
            }
        }
        if(counter[2] == 0)
        {
            if(counter[1] == 1)
            {
                ans++;
            }
            else
            {
                ans += counter[1] / 3 * 2;
            }
            cout << ans << "\n";
            continue;
        }
        if(counter[2] == 1)
        {
            counter[1] -= 2;
            counter[2]++;
            ans++;
        }
        int t= min(counter[1], counter[2] - 2);
        t = max(t, 0LL);
        ans += t;
        counter[1] -= t;
        counter[2] -= t;
        if(counter[1] == 0)
        {
            ans += (counter[2] - 2) / 3 * 3;
        }
        else
        {
            ans += counter[1] / 3 * 2;
        }
        cout << ans << "\n";
    }
    return 0;
}