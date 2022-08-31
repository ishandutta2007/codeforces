/*
    11.06.2018 17:17:04
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false    ;

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 2;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n;
        cin >> n;
        vector< int > bg;
        vector< int > en;
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            int v = 0;
            int mx1 = 0;
            for (int j = 0; j < s.length(); ++j)
            {
                if (s[j] == '(') {
                    v--;
                }
                else {
                    v++;
                }
                mx1 = max(mx1, v);
            }
            int mx2 = 0;
            v = 0;
            for (int j = s.length() - 1; j > -1; j--) {
                if (s[j] == ')') {
                    v--;
                }
                else {
                    v++;
                }
                mx2 = max(mx2, v);
            }
            if (mx2 == 0) {
                en.push_back(mx1);
                // cout << "en: " << mx1 << endl;
            }
            if (mx1 == 0) {
                bg.push_back(mx2);
                // cout << "bg: " << mx2 << endl;
            }
            // cout << mx1 << ' ' << mx2 << endl;
        }
        map< int, int > m1, m2;
        for (int i = 0; i < bg.size(); ++i)
        {
            if (m1.find(bg[i]) != m1.end()) {
                m1[bg[i]]++;
            }
            else {
                m1[bg[i]] = 1;
            }
        }
        for (int i = 0; i < en.size(); ++i)
        {
            if (m2.find(en[i]) != m2.end()) {
                m2[en[i]]++;
            }
            else {
                m2[en[i]] = 1;
            }
        }
        long long ans = 0;
        for (map< int, int >::iterator i = m1.begin(); i != m1.end(); i++)
        {
            long long u = i->second;
            if (m2.find(i->first) != m2.end()) {
                u *= (long long)m2[i->first];
                ans += u;
            }
        }
        cout << ans << endl;
    }
    fclose(stdout);
    return 0;
}