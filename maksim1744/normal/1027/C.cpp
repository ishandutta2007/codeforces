/*
    25.08.2018 14:21:21
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int test_count = 1;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int t;
        cin >> t;
        for (int in_test = 0; in_test < t; ++in_test)
        {
            int n;
            cin >> n;
            vector< int > a(n);
            map< int, int > m;
            for (int i = 0; i < n; ++i)
            {
                cin >> a[i];
                if (m.find(a[i]) == m.end()) {
                    m[a[i]] = 1;
                }
                else {
                    m[a[i]]++;
                }
            }
            bool square = false;
            int a_square = -1;
            vector< int > b;
            for (map< int, int >::iterator i = m.begin(); i != m.end(); i++)
            {
                if (i->second >= 4) {
                    square = true;
                    a_square = i->first;
                    break;
                }
                if (i->second >= 2) {
                    b.push_back(i->first);
                }
            }
            if (square) {
                for (int i = 0; i < 4; ++i)
                {
                    cout << a_square << ' ';
                }
                cout << endl;
                continue;
            }
            sort(b.begin(), b.end());
            pair< int, int > best;
            best.first = b[0];
            best.second = b[1];
            for (int i = 1; i < b.size() - 1; i++) {
                if (best.first * b[i + 1] < best.second * b[i]) {
                    best.first = b[i];
                    best.second = b[i + 1];
                }
            }
            cout << best.first << ' ' << best.first << ' ' << best.second << ' ' << best.second << endl;            
        }
    }
    fclose(stdout);
    return 0;
}