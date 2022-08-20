#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct rat
{
    int x, y;
    rat(){}
    rat (int a, int b)
    {
        x = a;
        y = b;
        if (a > b) {
            swap(a, b);
        }
        while (a != 0) {
            b = b % a;
            swap(a, b);
        }
        x /= b;
        y /= b;
    }
    bool operator==(rat r)
    {
        return x * r.y == y * r.x;
    }
};

bool operator < (const rat & r1, const rat & r2)
{
    return r1.x * r2.y < r2.x * r1.y;
}

int main()
{
    int m;
    cin >> m;
    string ss;
    getline(cin, ss);
    vector< pair<rat, int> > v(m);
    vector<int> cnt(m, 0);
    for (int i = 0; i < m; i++) {
        string s;
        getline(cin, s);
        int a = 0, b = 0, c = 0;
        int ind = 1;
        while (s[ind] != '+') {
            a *= 10;
            a += (s[ind] - '0');
            ind++;
        }
        ind++;
        while (s[ind] != ')') {
            b *= 10;
            b += (s[ind] - '0');
            ind++;
        }
        ind++;
        ind++;
        while (ind < s.length()) {
            c *= 10;
            c += (s[ind] - '0');
            ind++;
        }
        v[i] = make_pair(rat(a + b, c), i);
    }
    sort(v.begin(), v.end());
    int ind = 0;
    while (ind < m) {
        int i1 = ind;
        while (ind < m && v[ind].first == v[i1].first) {
            ind++;
        }
        for (int i = i1; i < ind; i++) {
            cnt[v[i].second] += ind - i1;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << cnt[i] << ' ';
    }
}