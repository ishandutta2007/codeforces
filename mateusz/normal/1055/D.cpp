#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

int n;
string from[N];
string to[N];
int low[N], high[N];
bool eq[N];

pair<string, string> findPair(int w) {
    high[w] = from[w].size() - 1;
    while (low[w] < from[w].size() && from[w][low[w]] == to[w][low[w]]) {
        low[w]++;
    }
    while (high[w] >= low[w] && from[w][high[w]] == to[w][high[w]]) {
        high[w]--;
    }
    
    string s = "", t = "";
    for (int i = low[w]; i <= high[w]; i++) {
        s += from[w][i];
        t += to[w][i];
    }
    
    return {s, t};
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> from[i];
    }
    
    
    for (int i = 0; i < n; i++) {
        cin >> to[i];
    }
    
    string s = "#";
    string t = ".";
    for (int i = 0; i < n; i++) {
        if (from[i] == to[i]) {
            eq[i] = true;
            continue;
        }
        auto p = findPair(i);
        if (s != "#" && (p.first != s || p.second != t)) {
            cout << "NO\n";
            return 0;
        }
        s = p.first;
        t = p.second;
    }
    
    while (true) {
        bool good = true;
        char last = 0;
        for (int i = 0; i < n; i++) {
            if (eq[i]) continue;
            int w = i;
            if (low[i] == 0 || (last && (from[w][low[w] - 1] != last))) {
                good = false;
                break;
            }
            last = from[w][low[w] - 1];
        }
        if (good) {
            s = last + s;
            t = last + t;
            for (int i = 0; i < n; i++) {
                if (eq[i]) continue;
                low[i]--;
            }
        } else {
            break;
        }
    }
    
    while (true) {
        bool good = true;
        char last = 0;
        for (int i = 0; i < n; i++) {
            if (eq[i]) continue;
            int w = i;
            if (high[i] == from[i].size() - 1 || (last && (from[w][high[w] + 1] != last))) {
                good = false;
                break;
            }
            last = from[w][high[w] + 1];
        }
        if (good) {
            s = s + last;
            t = t + last;
            for (int i = 0; i < n; i++) {
                if (eq[i]) continue;
                high[i]++;
            }
        } else {
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (eq[i] && from[i].find(s) != string::npos) {
            cout << "NO\n";
            return 0;
        }
        if (!eq[i] && from[i].find(s) != low[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
    cout << s << endl << t << endl;
    
    
    return 0;
}