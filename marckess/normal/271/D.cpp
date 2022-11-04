#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ((((n) % (k)) + (k) ) % (k))

struct trie {
    map<char, trie*> sig;
};

int agregar (int i, int j, string &s, trie *t) {
    int res = 0;

    for (int l = i; l < j; l++) {
        if (t->sig[s[l]] == 0) {
            res++;
            t->sig[s[l]] = new trie();
        }
        t = t->sig[s[l]];
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    char c;
    bitset<255> bs;

    cin >> s;
    for (int i = 'a'; i <= 'z'; i++) {
        cin >> c;
        bs[i] = c == '1';
    }

    vi acu;
    for (char c : s)
        acu.push_back(!bs[c] ? 1 : 0);
    for (int i = 1; i < acu.size(); i++)
        acu[i] += acu[i-1];

    int i = 0, j = 0, k, res = 0;
    trie *t = new trie();

    cin >> k;
    while (i < s.size()) {
        while (j < s.size() && acu[j] - (i ? acu[i-1] : 0) <= k)
            j++;
        res += agregar(i, j, s, t);
        i++;
    }
    cout << res << endl;

    return 0;
}