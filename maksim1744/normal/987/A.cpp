/*
    30.05.2018 13:56:49
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
        string col[] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
        map< string, int > mp;
        mp["purple"] = 0;
        mp["green"] = 1;
        mp["blue"] = 2;
        mp["orange"] = 3;
        mp["red"] = 4;
        mp["yellow"] = 5;
        vector< bool > has(6, false);
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            has[mp[s]] = true;
        }
        cout << 6 - n << endl;
        for (int i = 0; i < 6; ++i)
        {
            if (!has[i]) {
                cout << col[i] << endl;
            }
        }
    }
    fclose(stdout);
    return 0;
}