#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int ttoi(string s) {
    stringstream s1, s2;
    s1 << s.substr(0, 2);
    s2 << s.substr(3, 2);
    int a, b;
    s1 >> a;
    s2 >> b;
    return 60*a + b;
}

string itot(int t) {
    int a = t / 60, b = t % 60;
    stringstream ss;
    if (a < 10) ss << "0";
    ss << a << ":";
    if (b < 10) ss << "0";
    ss << b;
    return ss.str();
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    string s, t;
    cin >> s >> t;
    int a = ttoi(s), b = ttoi(t);
    int c = a - b;
    if (c < 0) c += 1440;

    cout << itot(c) << '\n';
    return 0;
}