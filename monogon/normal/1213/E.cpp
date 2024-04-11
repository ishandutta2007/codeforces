
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n;
string s, t;
int mat[3][3];

string solve(int n, string s, string t) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            mat[i][j] = 0;
        }
    }
    mat[s[0] - 'a'][s[1] - 'a'] = true;
    mat[t[0] - 'a'][t[1] - 'a'] = true;
    string str = "";
    if(!mat[0][1] && !mat[1][2] && !mat[2][0]) {
        // 3-cycle
        for(int i = 0; i < n; i++) {
            str += "abc";
        }
        return str;
    }else if(!mat[0][2] && !mat[2][1] && !mat[1][0]) {
        // 3-cycle
        for(int i = 0; i < n; i++) {
            str += "acb";
        }
        return str;
    }
    char c[3];
    if(s[0] == t[0]) {
        // ab, ac
        // bbbcccaaa
        c[0] = s[1];
        c[1] = t[1];
        c[2] = s[0];
    }else if(s[1] == t[0]) {
        // ab, ba
        // aaacccbbb
        c[0] = s[0];
        c[2] = s[1];
        for(int i = 0; i < 3; i++) {
            if(i + 'a' != s[0] && i + 'a' != s[1]) {
                c[1] = i + 'a';
                break;
            }
        }
    }else {
        // ab, cb
        // bbbaaaccc
        c[0] = s[1];
        c[1] = s[0];
        c[2] = t[0];
    }
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < n; i++) {
            str.push_back(c[j]);
        }
    }
    return str;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s >> t;
    cout << "YES" << endl << solve(n, s, t) << endl;
}