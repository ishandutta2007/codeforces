/*
    17.05.2018 20:16:38
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

const bool debug = false;

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
        vector< int > a(n);
        vector< pi > ks(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            ks[i] = pi(a[i], i);
        }
        sort(ks.begin(), ks.end());
        int loc = 0, mnk = 0;
        set< int > ls, rs;
        vector< int > pr(n, -1);
        // vector< int > ln(n, 0);
        vector< int > lnc(n + 1, 0);
        int i = 0;
        int lastc = 0;
        int cnt = 0;
        while (i < ks.size()) {
            int ind = i;
            int k = ks[i].first;
            while (ind >= 0 && ks[ind].first == k) {
                int j = ks[ind].second;
                if (ls.find(j + 1) != ls.end()) {
                    if (rs.find(j - 1) != rs.end()) {
                        lnc[pr[j + 1] - (j + 1) + 1]--;
                        lnc[j - 1 - pr[j - 1] + 1]--;
                        lnc[pr[j + 1] - pr[j - 1] + 1]++;
                        cnt--;
                        lastc = pr[j + 1] - pr[j - 1] + 1;
                        int uuu = pr[j - 1];
                        pr[pr[j - 1]] = pr[j + 1];
                        pr[pr[j + 1]] = uuu;
                        ls.erase(j + 1);
                        rs.erase(j - 1);
                    }
                    else {
                        lnc[pr[j + 1] - (j + 1) + 1]--;
                        lnc[pr[j + 1] - j + 1]++;
                        lastc = pr[j + 1] - j + 1;
                        pr[j] = pr[j + 1];
                        pr[pr[j + 1]] = j;
                        ls.erase(j + 1);
                        ls.insert(j);
                    }
                }
                else {
                    if (rs.find(j - 1) != rs.end()) {
                        lnc[j - 1 - pr[j - 1] + 1]--;
                        lnc[j - pr[j - 1] + 1]++;
                        lastc = j - pr[j - 1] + 1;
                        pr[j] = pr[j - 1];
                        pr[pr[j - 1]] = j;
                        rs.erase(j - 1);
                        rs.insert(j);
                    }
                    else {
                        pr[j] = j;
                        lastc = 1;
                        cnt++;
                        lnc[1]++;
                        ls.insert(j);
                        rs.insert(j);
                    }
                }
                ind--;
            }
            if (lnc[lastc] == cnt) {
                if (lnc[lastc] > loc) {
                    loc = lnc[lastc];
                    mnk = k + 1;
                }
            }
            i++;
            while (i < n - 1 && a[i] == a[i + 1]) {
                i++;
            }
        }
        cout << mnk << endl;
    }
    fclose(stdout);
    return 0;
}