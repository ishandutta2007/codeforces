#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> AB;
    vector<int> BA;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == 'A' && s[i + 1] == 'B') AB.push_back(i);
        if (s[i] == 'B' && s[i + 1] == 'A') BA.push_back(i);
    }
    if (AB.size() * BA.size() == 0) {
        cout << "NO\n";
        return 0;
    }
    if (AB.size() + BA.size() >= 4) {
        cout << "YES";
        return 0;
    }
    if (AB.size() * BA.size() == 1) {
        cout << ((AB[0] - BA[0]) * (AB[0] - BA[0]) == 1 ? "NO" : "YES");
    }
    if (AB.size() == 2) {
        cout << (((AB[0] - BA[0]) * (AB[0] - BA[0]) == 1) &&
                 ((AB[1] - BA[0]) * (AB[1] - BA[0]) == 1) ? "NO" : "YES");
    }
    if (BA.size() == 2) {
        cout << (((BA[0] - AB[0]) * (BA[0] - AB[0]) == 1) &&
                 ((BA[1] - AB[0]) * (BA[1] - AB[0]) == 1) ? "NO" : "YES");
    }
}