#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 1e5 + 5;

int n, k, kol[26];
string s;
string q[N];

signed main()
{/*
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    int o;
    cin >> o;
    while (o--) {
        cin >> n >> k >> s;
        string t = "";
        for (int i = 0; i < k; i++)
            q[i].clear();
        for (int i = 0; i < 26; i++)
            kol[i] = 0;
        for (int i = 0; i < s.size(); i++)
            kol[s[i] - 'a']++;
        int cur = 0;
        while (kol[cur] == 0)
            cur++;

        if (kol[cur] >= k) {
            kol[cur] -= k;
            t += char(cur + 'a');
            int v = 0, pp = 0;
            for (int i = 0; i < 26; i++)
                if (kol[i] > 0)
                    v++, pp = i;
            if (v == 0) {
                cout << t << "\n";
                continue;
            }
            if (v == 1) {
                for (int j = 0; j < (kol[pp] - 1) / k + 1; j++)
                    t += char(pp + 'a');
                cout << t << "\n";
                continue;
            }
            for (int i = 0; i < 26; i++)
                while (kol[i] > 0)
                    t += char(i + 'a'), kol[i]--;
        } else {
            int sum = 0;
            while (sum + kol[cur] < k)
                sum += kol[cur], cur++;
            t += char(cur + 'a');
        }
        cout << t << "\n";
    }
    return 0;
}