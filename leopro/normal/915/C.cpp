#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int max_less(int begin, char m, const string &a) {
    if (a.empty()) return -1;
    int p = begin;
    for (int i = begin; i < a.size(); ++i) {
        if (a[p] >= m) {
            p = i;
            continue;
        }
        if (a[i] > a[p] && a[i] < m) p = i;
    }
    return (a[p] < m ? p : -1);
}

int same(int begin, char m, const string &a) {
    for (int i = begin; i < a.size(); ++i) {
        if (a[i] == m) return i;
    }
    return -1;
}

int max(int begin, const string &a) {
    int p = begin;
    for (int i = begin; i < a.size(); ++i) {
        if (a[i] > a[p]) p = i;
    }
    return p;
}

string create(string a, const string &b, int n) {
    for (int i = 0; i < n; ++i) {
        int p = same(i, b[i], a);
        swap(a[p], a[i]);
    }
    if (n >= a.size()) return a;
    if (max_less(n, b[n], a) == -1) return "";
    swap(a[n], a[max_less(n, b[n], a)]);
    for (int i = n + 1; i < a.size(); ++i) {
        swap(a[i], a[max(i, a)]);
    }
    return a;
}

int contains(string a, const string &b) {
    for (int i = 0; i < b.size(); ++i) {
        if (same(0, b[i], a) != -1) {
            a[same(0, b[i], a)] = 'x';
            continue;
        }
        return i;
    }
    return a.size();
}

int main() {
    string a, b;
    cin >> a >> b;
    if (b.size() > a.size()) {
        b = "";
        for (int i = 0; i < a.size(); ++i) {
            b += '9';
        }
    }
    int c = contains(a, b);
    string r = create(a, b, 0);
    for (int i = 0; i <= c; ++i) {
        string s = create(a, b, i);
        if (s.empty()) continue;
        r = s;
    }
    cout << r << endl;
    return 0;
}