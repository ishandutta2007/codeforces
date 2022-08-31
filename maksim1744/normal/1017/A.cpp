/*
    24.08.2018 14:46:33
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int s = a + b + c + d;
        int place = 1;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> a >> b >> c >> d;
            if (a + b + c + d > s) {
                place++;
            }
        }
        cout << place << endl;
    }
    fclose(stdout);
    return 0;
}