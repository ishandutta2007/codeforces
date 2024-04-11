#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
string s[N];
bool done[N];
int last[256];

string matches(string a, string b) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                if (j > i) {
                    swap(a, b);
                    swap(i, j);
                }
                for (int k = j; k >= 0; k--) {
                    if (b[k] != a[i - (j - k)]) {
                        return "";
                    }
                }
                for (int k = j + 1; k < b.size(); k++) {
                    if (i + (k - j) >= a.size()) {
                        a += b[k];
                    }
                    if (b[k] != a[i + (k - j)]) {
                        return "";
                    }
                }
                return a;
            }
        }
    }
}

bool hasCommon(string a, string b) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        string cp = s[i];
        sort(cp.begin(), cp.end());
        for (int j = 1; j < cp.size(); j++) {
            if (cp[j] == cp[j - 1]) {
                cout << "NO\n";
                return 0;
            }
        }
        
        for (int j = 0; j < s[i].size(); j++) {
            int id = last[s[i][j]];
            if (last[s[i][j]] > 0 && !done[last[s[i][j]]]) {
                string match = matches(s[id], s[i]);
                done[id] = true;
                if (match == "") {
                    cout << "NO\n";
                    return 0;
                }
                s[i] = match;
            }
        }
        for (int j = 0; j < s[i].size(); j++) last[s[i][j]] = i;
    } 
    
    vector<string> candidates;
    for (int i = 1; i <= n; i++) {
        if (!done[i]) candidates.push_back(s[i]);
    }
    sort(candidates.begin(), candidates.end());
    string ans;
    for (int i = 0; i < candidates.size(); i++) {
        ans += candidates[i];
    }
    string cp = ans;
    sort(cp.begin(), cp.end());
    for (int i = 1; i < cp.size(); i++) {
        if (cp[i] == cp[i - 1]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}