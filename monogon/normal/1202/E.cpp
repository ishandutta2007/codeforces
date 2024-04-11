
#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct node {
    node() {
        occ = 0;
    }
    int occ;
    map<char, node*> edge;
};
const int MAX_N = 2e5 + 5;
string t, s[MAX_N];
int n, sumlen;
node *trie;
int suf[MAX_N], pref[MAX_N], kmp[MAX_N];

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

void solve(int *arr) {
    // arr[i] = # occurrences starting at position i.
    int N = t.length();
    fill(arr, arr + N, 0);
    trie = new node();
    for(int i = 0; i < n; i++) {
        int len = s[i].length();
        if(len * len < sumlen) {
            // short string, add to trie
            node *p = trie;
            for(int j = 0; j < len; j++) {
                if(p->edge.count(s[i][j]) == 0) {
                    node *q = new node();
                    p->edge[s[i][j]] = q;
                    p = q;
                }else {
                    p = p->edge[s[i][j]];
                }
            }
            p->occ++;
        }else {
            // long string, check kmp
            calcKMP(s[i]);
            int j = 0, k = 0;
            while(j < N) {
                if(s[i][k] == t[j]) {
                    j++; k++;
                }
                if(k == len) {
                    arr[j - k]++;
                    k = kmp[k - 1];
                }else if(j < N && s[i][k] != t[j]) {
                    if(k == 0) {
                        j++;
                    }else {
                        k = kmp[k - 1];
                    }
                }
            }
        }
    }
    for(int i = 0; i < N; i++) {
        node *p = trie;
        int j = i;
        while(j < N && p->edge.count(t[j])) {
            p = p->edge[t[j]];
            arr[i] += p->occ;
            j++;
        }
    }
}

string reverse(string s) {
    string res = "";
    int len = s.length();
    for(int i = len - 1; i >= 0; i--) {
        res.push_back(s[i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t >> n;
    ll f = 0;
    int N = t.length();

    for(int i = 0; i < n; i++) {
        cin >> s[i];
        sumlen += s[i].length();
    }
    solve(suf);
    // reverse t and s[i]
    t = reverse(t);
    for(int i = 0; i < n; i++) {
        s[i] = reverse(s[i]);
    }
    solve(pref);
    ll num = 0;
    for(int i = 0; i < N - 1; i++) {
        num += ((ll) pref[N - i - 1]) * ((ll) suf[i + 1]);
    }
    cout << num << endl;
}