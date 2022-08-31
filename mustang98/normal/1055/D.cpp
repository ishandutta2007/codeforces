#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 3111, inf = 1000111222;

string a[max_n];
string b[max_n];
bool eq[max_n];
char s[max_n];
int st[max_n];
int n;
int pr[max_n * 3];

string pattern = "";
string pattern_to = "";

int mins = inf;
void findp(int ind) {
    string& s1 = a[ind];
    string& s2 = b[ind];
    int s, f;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            s = i;
            break;
        }
    }
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            f = i;
        }
    }
    st[ind] = s;
    mins = min(mins, s);
    string pat = s1.substr(s, f - s + 1);
    string pat_to = s2.substr(s, f - s + 1);
    if (pattern == "") {
        pattern = pat;
        pattern_to = pat_to;
    } else {
        if (pattern != pat || pattern_to != pat_to) {
            cout << "NO";
            exit(0);
        }
    }
}

bool check(int ind, char c) {
    for (int i = 0; i < n; ++i) {
        if (eq[i]) continue;
        int pos = st[i] + ind;
        if (pos < 0 || pos >= a[i].size()) {
            return false;
        }
        if (a[i][pos] != c) {
            return false;
        }
    }
    return true;
}

int prf(int ind) {
    string s = pattern + "#" + a[ind];
    pr[0] = 0;
    //cout << s << endl;
    for (int i = 1; i < s.size(); ++i) {
        int k = pr[i - 1];
        while (k > 0 && s[i] != s[k]) {
            k = pr[k - 1];
        }
        if (s[i] == s[k]) {
            pr[i] = k + 1;
        } else {
            pr[i] = 0;
        }
        if (i >= pattern.size() && pr[i] == pattern.size()) {
            return i - 2 * pattern.size();
        }
      //  cout << pr[i] << ' ';
    }
    //cout << endl;
    return inf;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        a[i] = s;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        b[i] = s;
        if (a[i] == b[i]) {
            eq[i] = 1;
        }
    }

    string anyw;
    int fa;

    for (int i = 0; i < n; ++i) {
        if (eq[i]) continue;
        findp(i);
    }


    for (int i = 0; i < n; ++i) {
        if (eq[i]) continue;
        anyw = a[i];
        fa = st[i];
        break;
    }

    reverse(pattern.begin(), pattern.end());
    reverse(pattern_to.begin(), pattern_to.end());
    int addl = 0, addr = 0;
    for (int i = fa - 1; i >= 0; --i) {
        if (check(i - fa, anyw[i])) {
            ++addl;
            pattern += anyw[i];
            pattern_to += anyw[i];
        } else {
            break;
        }
    }

    reverse(pattern.begin(), pattern.end());
    reverse(pattern_to.begin(), pattern_to.end());
    int ta = fa + pattern.size() - addl - 1;
    for (int i = ta + 1; i < anyw.size(); ++i) {
        if (check(i - fa, anyw[i])) {
            ++addr;
            pattern += anyw[i];
            pattern_to += anyw[i];
        } else {
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        st[i] -= addl;
    }

    for (int i = 0; i < n; ++i) {
        if (eq[i] && prf(i) != inf) {
            cout << "NO";
            return 0;
        }
        if (!eq[i] && prf(i) != st[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << pattern << endl;
    cout << pattern_to << endl;

    return 0;
}