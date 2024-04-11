
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1e5 + 5, MAX_STR = 1e6 + 5;
int n;
string s[MAX_N];
char finalstr[MAX_STR];
int kmp[MAX_STR];

void calcKMP(string str) {
    int len = 0;
    kmp[0] = 0;
    int M = str.length();
    int i = 1;
    while(i < M) {
        if(str[i] == str[len]) {
            kmp[i++] = ++len;
        }else if(len == 0) {
            kmp[i++] = 0;
        }else {
            len = kmp[len - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    strcpy(finalstr, s[0].c_str());
    cout << s[0];
    int N = s[0].length();
    for(int num = 1; num < n; num++) {
        // match s[i] in finalstr suffix of length at most s[i].length()
        calcKMP(s[num]);
        int M = s[num].length();
        int i = max(0, N - M);
        int j = 0;
        while(i < N) {
            if(s[num][j] == finalstr[i]) {
                i++;
                j++;
            }
            if(i == N) {
                break;
            }
            if(j == M) {
                j = kmp[j - 1];
            }else if(i < N && s[num][j] != finalstr[i]) {
                if(j != 0) {
                    j = kmp[j - 1];
                }else {
                    i++;
                }
            }
        }
        for(int k = j; k < M; k++) {
            finalstr[N + k - j] = s[num][k];
        }
        N += M - j;
        cout << s[num].substr(j);
    }
    cout << endl;
}