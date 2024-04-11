/*
    30.05.2018 17:14:08
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

struct item
{
    int p, v;
    bool end;
    map< char, int > m;
    item(): p(-1), v(0), end(false) {}
    item(int p): p(p), v(0), end(false) {}
};

vector< item > bor;

void init() {
    bor.clear();
    bor.push_back(item());
}

void add(string & s, int i = 0, int j = 0) {
    bor[i].v++;
    if (j == (int)s.length()) {
        bor[i].end = true;
        return;
    }
    if (bor[i].m.find(s[j]) == bor[i].m.end()) {
        bor[i].m[s[j]] = bor.size();
        bor.push_back(item(i));
    }
    add(s, bor[i].m[s[j]], j + 1);
}

void show() {
    for (int i = 0; i < bor.size(); ++i)
    {
        cout << "======= " << i << " =======\n";
        if (bor[i].end) {
            cout << "end = true\n";
        }
        for (map< char, int >:: iterator it = bor[i].m.begin(); it != bor[i].m.end(); it++) {
            cout << "child['" << it -> first << "'] = " << it -> second << endl;
        }
    }
}

multiset< int > solve(int i) {
    multiset< int > s;
    for (map< char, int >:: iterator it = bor[i].m.begin(); it != bor[i].m.end(); it++) {
        multiset< int > ms = solve(it -> second);
        for (multiset< int >::iterator i = ms.begin(); i != ms.end(); i++) {
            s.insert((*i) - 1);
        }
    }
    s.insert(0);
    if (!bor[i].end && i != 0) {
        s.erase(s.begin());
    }
    // cout << i << ": ";
    // for (set< int >::iterator i = s.begin(); i != s.end(); i++)
    // {
    //     cout << *i << ' ';
    // }
    // cout << endl;
    return s;
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
        init();
        int n;
        cin >> n;
        int sm = 0;
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            // cout << '<' << s << ">\n";
            add(s);
        }
        // show();
        multiset< int > m = solve(0);
        for (multiset< int >::iterator i = m.begin(); i != m.end(); i++)
        {
            // cout << *i << ' ';
            sm += *i;
        }
        cout << endl;
        cout << -sm << endl;
    }
    fclose(stdout);
    return 0;
}