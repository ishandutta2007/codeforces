#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;

int main() {

    cin >> n >> k;
    cin >> s;
    
    set<char> letters;
    for (auto c : s) letters.insert(c);
    vector<char> v;
    for (auto c : letters) v.push_back(c);
    
    string t;
    for (int i = 0; i < min(n, k); i++) {
        t += s[i];
    }
    
    if (k > n) {
        for (int i = 0; i < k - n; i++) {
            t += v[0];
        }
        cout << t << endl;
        return 0;
    }
    
    int pos = k - 1;
    while (t[pos] == v.back()) pos--;
    
    for (int i = 0; i < v.size(); i++) {
        if (t[pos] == v[i]) {
            t[pos] = v[i + 1];
            break;
        }
    }
    
    for (int i = pos + 1; i < k; i++) {
        t[i] = v[0];
    }
    
    cout << t << endl;
    
    return 0;
}