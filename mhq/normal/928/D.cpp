#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) (int)x.size()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef vector<pii> vpii;

template<typename T>
T getint() {
    T x=0,p=1;
    char ch;
    do{ch=getchar();}while(ch <= ' ');
    if(ch=='-')p=-1,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*p;
}

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

template<typename T1,typename T2>bool umin(T1 &x,const T2&y){if(x>y)return x=y,true;return false;}
template<typename T1,typename T2>bool umax(T1 &x,const T2&y){if(x<y)return x=y,true;return false;}

const int maxn=(int)3e5+3;
const int inf=(int)1e9+5;
const int mod=(int)1e9+7;
const ll llinf=(ll)1e18+5;
const ld pi=acos(-1.0);

map <string, int> was;
int nxt[maxn][26];
int f[maxn];
int sz = 1;

void add(string s) {
    int v = 1;
    for(int i = 0; i < s.length(); ++i) {
        int x = s[i] - 'a';
        if (nxt[v][x] == 0) nxt[v][x] = ++sz;
        v = nxt[v][x];
        f[v]++;
    }
}

int calc(string s) {
    int n = s.length();
    int v = 1;
    for(int i = 0; i < n; ++i) {
        int x = s[i] - 'a';
        if (nxt[v][x] == 0) return n;
        v = nxt[v][x];
        if (f[v] != 1) continue;

        int cnt = i + 1;
        int pos = i + 1;
        while(pos < n) {
            int x = s[pos] - 'a';
            if (nxt[v][x] == 0) break;
            v = nxt[v][x];
            pos++;
        }
        for(int x = 0; x < 26; ++x) if (nxt[v][x]) return n;
        return min(cnt + 1 + n - pos, n);
    }
    return n;
}

int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(0);

    string s;
    int res = 0;
    while(getline(cin, s)) {
        int n = s.length();
        for(int i = 0; i < n; ) {
            if (!isalpha(s[i])) {
                res++;
                i++;
                continue;
            }
            string t = "";
            while(i < n && isalpha(s[i])) {
                t += s[i++];
            }
            int c = calc(t);
            res += c;
            if (!was.count(t)) {
                was[t] = true;
                add(t);
            }
        }
        res++;
    }
    cout << res << endl;
    return 0;
}