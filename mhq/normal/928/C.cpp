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

const int maxn=(int)1e3+3;
const int inf=(int)1e9+5;
const int mod=(int)1e9+7;
const ll llinf=(ll)1e18+5;
const ld pi=acos(-1.0);

ll get(string s) {
    ll ret = 0, p = 1;
    for(int i = 0; i < s.length(); ++i) {
        ret += (s[i] - 'a' + 1) * p;
        p *= 27;
    }
    return ret;
}

map < pair <ll, int> , int > q;
int c = 0;

ll id[maxn];
int ver[maxn];
map <ll, string> name;

int get(string s, int x) {
    ll y = get(s);
    if (!name.count(y)) name[y] = s;

    int &r = q[make_pair(y, x)];
    if (r == 0) {
        r = ++c;
        id[r] = y;
        ver[r] = x;
    }
    return r;
}

map < ll, vector < pair <int, int> > > r;
vector <int> g[maxn];
vector <int> d[maxn];
map <ll, int> was;

int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string s;
        int x;
        cin >> s >> x;
        int num = get(s, x);

        int m;
        cin >> m;
        while(m--) {
            string t; int y;
            cin >> t >> y;
            int cnum = get(t, y);
            g[num].push_back(cnum);
        }
    }

    d[0].push_back(1);
    vector < pair <string, int> > answer;
    for(int i = 0; i < 1000; ++i) {
        for(int x: d[i]) was[ id[x] ] = true;

        map <ll, int> nxt;
        for(int x: d[i]) {
            if (i != 0) answer.push_back(make_pair(name[ id[x] ], ver[x]));
            for(int y: g[x]) {
                if (was.count(id[y])) continue;
                int &r = nxt[id[y]];
                if (r == 0) r = y;
                else if (ver[r] < ver[y]) r = y;
            }
        }
        for(auto x: nxt) d[i + 1].push_back(x.second);
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for(auto x: answer) {
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}