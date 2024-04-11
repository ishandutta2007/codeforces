/*
    30.05.2018 14:07:23
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

string comp(int a, int b) {
    if (a == b) {
        return "=\n";
    }
    if (a < b) {
        return "<\n";
    }
    if (a > b) {
        return ">\n";
    }
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 3;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int x, y;
        cin >> x >> y;
        if (x >= 3 && y >= 3) {
            cout << comp(y, x);
        }
        else if (x <= 3 && y <= 3) {
            cout << comp(x, y);
        }
        else {
            if (x == 1) {
                cout << "<\n";
            }
            else if (x == 2) {
                if (y == 4) {
                    cout << "=\n";
                }
                else {
                    cout << ">\n";
                }
            }
            else if (y == 1) {
                cout << ">\n";
            }
            else {
                if (x == 4) {
                    cout << "=\n";
                }
                else {
                    cout << "<\n";
                }
            }
        }
    }
    fclose(stdout);
    return 0;
}