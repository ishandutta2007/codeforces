#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int calc00(string s) {
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '0') {
            ans += (s.size() - 1 - i);
            if (i != s.size() - 1) {
                //swap(s[i], s[s.size() - 1]);
                char c = s[i];
                s.erase(s.begin() + i);
                s +=  c;
            }
            break;
        }
    }
    if (s[s.size() - 1] != '0') return inf;

    for (int i = s.size() - 2; i >= 0; --i) {
        if (s[i] == '0') {
            ans += (s.size() - 2 - i);
            if (i != s.size() - 2) {
                char c = s[i];
                s.erase(s.begin() + i);
                s += c;
                swap(s[s.size() - 1], s[s.size() - 2]);
            }
            break;
        }
    }
    if (s[s.size() - 2] != '0') return inf;
    return ans;
}

int calc25(string s) {
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '5') {
            ans += (s.size() - 1 - i);
            if (i != s.size() - 1) {
                //swap(s[i], s[s.size() - 1]);
                char c = s[i];
                s.erase(s.begin() + i);
                s += c;
            }
            break;
        }
    }
    if (s[s.size() - 1] != '5') return inf;
    for (int i = s.size() - 2; i >= 0; --i) {
        if (s[i] == '2') {
            ans += (s.size() - 2 - i);
            if (i != s.size() - 2) {
                //swap(s[i], s[s.size() - 2]);
                char c = s[i];
                s.erase(s.begin() + i);
                s += c;

                swap(s[s.size() - 1], s[s.size() - 2]);
            }
            break;
        }
    }
    if (s[s.size() - 2] != '2') return inf;
    int cnt0 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '0') break;
        ++cnt0;
    }
    if (cnt0 && cnt0 == s.size() - 2) {
        return inf;
    }
    ans += cnt0;
    return ans;
}

int calc75(string s) {
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '5') {
            ans += (s.size() - 1 - i);
            if (i != s.size() - 1) {
                //swap(s[i], s[s.size() - 1]);
                char c = s[i];
                s.erase(s.begin() + i);
                s += c;
            }
            break;
        }
    }
    if (s[s.size() - 1] != '5') return inf;

    for (int i = s.size() - 2; i >= 0; --i) {
        if (s[i] == '7') {
            ans += (s.size() - 2 - i);
            if (i != s.size() - 2) {
                //swap(s[i], s[s.size() - 2]);
                char c = s[i];
                s.erase(s.begin() + i);
                s += c;

                swap(s[s.size() - 1], s[s.size() - 2]);
            }
            break;
        }
    }
    if (s[s.size() - 2] != '7') return inf;
    int cnt0 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '0') break;
        ++cnt0;
    }
    if (cnt0 && cnt0 == s.size() - 2) {
        return inf;
    }
    ans += cnt0;
    return ans;
}

int calc50(string s) {
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '0') {
            ans += (s.size() - 1 - i);
            if (i != s.size() - 1) {
                //swap(s[i], s[s.size() - 1]);
                char c = s[i];
                s.erase(s.begin() + i);
                s += c;
            }
            break;
        }
    }
    //
    //cout << s << endl;
    if (s[s.size() - 1] != '0') return inf;

    for (int i = s.size() - 2; i >= 0; --i) {
        if (s[i] == '5') {
            ans += (s.size() - 2 - i);
            if (i != s.size() - 2) {
                //swap(s[i], s[s.size() - 2]);
                char c = s[i];
                s.erase(s.begin() + i);
                s += c;
                swap(s[s.size() - 1], s[s.size() - 2]);
            }
            break;
        }
    }
    if (s[s.size() - 2] != '5') return inf;
    int cnt0 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '0') break;
        ++cnt0;
    }
    if (cnt0 && cnt0 == s.size() - 2) {
        return inf;
    }
    ans += cnt0;
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    if (s.size() < 2) {
        cout << -1;
        return 0;
    }
    int ans = min(min(calc00(s), calc75(s)), min(calc25(s), calc50(s)));
    if (ans == inf) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}