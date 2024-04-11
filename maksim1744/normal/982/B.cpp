/*
    17.05.2018 19:41:29
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

typedef pair<int, int> pi;


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
        vector< int > w(n);
        set< pi > s1;
        set< pi > s2;
        for (int i = 0; i < n; ++i)
        {
            cin >> w[i];
            s2.insert(pi(w[i], i + 1));
        }
        char c;
        for (int i = 0; i < 2 * n; ++i)
        {
            cin >> c;
            if (c == '1') {
                pi p = *s1.begin();
                cout << p.second << ' ';
                s1.erase(s1.begin());
            }
            else {
                pi p = *s2.begin();
                cout << p.second << ' ';
                s2.erase(s2.begin());
                p.first = -p.first;
                s1.insert(p);
            }
        }
        cout << '\n';
    }
    fclose(stdout);
    return 0;
}