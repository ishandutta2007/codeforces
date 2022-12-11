#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int n;
string s, t;
set<string> answer;

bool check_string(string &a, string &b) {
    int pos = 0;
    for (int i = 0; i < b.size(); i++) {
        while (true) {
            if (pos == a.size() ) {
                return false;
            }
            if (a[pos] == b[i] ) {
                break;
            }
            pos += 1;
        }
        pos += 1;
    }
    return true;
}

void check(string &candidate) {
    if (check_string(candidate, s) && check_string(candidate, t) ) {
        answer.insert(candidate);
    }
}

void solve() {
	cin >> n;
    cin >> s >> t;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i] ) {
            pos = i;
            break;
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        string candidate = "";
        for (int i = 0; i < n; i++) {
            if (i == pos) {
                candidate += c;
            }
            candidate += s[i];
        }
        check(candidate);
    }

    for (char c = 'a'; c <= 'z'; c++) {
        string candidate = "";
        for (int i = 0; i < n; i++) {
            if (i == pos) {
                candidate += c;
            }
            candidate += t[i];
        }
        check(candidate);
    }

    cout << answer.size() << "\n";
}

int main() {
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
    return 0;
}