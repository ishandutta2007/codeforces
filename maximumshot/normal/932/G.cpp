#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
const int inf = 1e9;
const ll inf64 = 1e18;
 
const int mod = inf + 7;
 
inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}
 
inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}
 
inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}
 
inline void _inc(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}
 
inline void _dec(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}
 
inline int _binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        pw >>= 1;
    }
    return res;
}
 
inline int _div(int a, int b) {
    return _mul(a, _binpow(b, mod - 2));
}
 
void read(string& s) {
    cin >> s;
}
 
void gen(string& s) {
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    int n = 2 * (rnd() % 3 + 1);
    s.resize(n, '?');
    for (int i = 0; i < n; i++) {
        s[i] = rnd() % 5 == 0 ? 'a' : 'b';
    }
}
 
string join_halfs(string s) {
    int n = (int) s.size();
    string t;
    for (int i = 0; i < n / 2; i++) {
        t.push_back(s[i]);
        t.push_back(s[n - 1 - i]);
    }
    return t;
}
 
int slow(string s) {
    s = join_halfs(s);
    int n = (int) s.size();
    s = "#" + s;
    vector<int> dp(n + 1);
    dp[0] = 1;
    cout << s << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            if ((i - j + 1) % 2) continue;
            string hlp = s.substr(j, i - j + 1);
            string rhlp = hlp; reverse(rhlp.begin(), rhlp.end());
            if (hlp == rhlp) {
                _inc(dp[i], dp[j - 1]);
            }
        }
    }
    return dp[n];
}
 
const int N = 2e6 + 5;
struct EerTree {char s[N];map<char, int> nxt[N];
int n,sz,link[N],len[N],diff[N],dp[N][2],slink[N],max_suff;
int ans[N]; // number of partitions into palindromes of even length
void clr() {fill(s, s + N, 0);fill(link, link + N, 0);fill(len, len + N, 0);
fill(nxt,nxt+N,map<char,int>());fill(diff,diff+N,0);fill((int*)dp,(int*)dp+N*2,0);
fill(slink, slink + N, 0);n = 0;sz = 0;max_suff = 0;fill(ans, ans + N, 0);}
EerTree() {clr();s[0] = '#'; // not in alphabet
link[0] = 1;link[1] = 0;len[0] = -1;sz = 2;ans[0] = 1;}
int get_link(int from){while(s[n]!=s[n-len[from]-1]){from=link[from];}return from;}
void add_symbol(char c) {s[++n]=c;max_suff=get_link(max_suff);if(!nxt[max_suff].count(c)){
{int x = get_link(link[max_suff]);link[sz] = nxt[x].count(c) ? nxt[x][c] : 1;}
len[sz] = len[max_suff] + 2;diff[sz] = len[sz] - len[link[sz]];
slink[sz]=diff[sz]==diff[link[sz]] ? slink[link[sz]] : link[sz];nxt[max_suff][c] = sz++;}
max_suff=nxt[max_suff][c];for(int x = max_suff;len[x]>0;x=slink[x]){dp[x][0]=dp[x][1]=0;
int j=n-(len[slink[x]]+diff[x]);_inc(dp[x][j&1],ans[j]);if(diff[x] == diff[link[x]]) {
_inc(dp[x][0],dp[link[x]][0]);_inc(dp[x][1],dp[link[x]][1]);}_inc(ans[n],dp[x][n&1]);}}};
 
int fast(string s) {
    int n = (int) s.size();
    s = join_halfs(s);
    EerTree eertree;
    for (char c : s) {
        eertree.add_symbol(c);
    }
    return eertree.ans[n];
}
 
void WORK() {
    string s;
    read(s);
//    cout << slow(s) << "\n";
    cout << fast(s) << "\n";
}
 
void TEST() {
    while (1) {
        string s;
        gen(s);
        cout << "s = " << s << endl;
        int sl = slow(s);
        int fs = fast(s);
        if (sl == fs) {
            cout << "OK (" << fs << ")" << endl;
        } else {
            cout << "WA" << endl;
            cout << "exp = " << sl << endl;
            cout << "fnd = " << fs << endl;
            break;
        }
    }
}
 
int main() {
 
#ifdef debug
    freopen("input.txt", "r", stdin);
#endif
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    WORK();
//    TEST();
 
    return 0;
}