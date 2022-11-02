//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii; 

const int maxN = 600 + 10;

bool c[maxN][maxN];
int n;

set<int> oth;
vector<int> que;

int ask(vector<int> a) { 
    if( a.size() <= 1 ) return 0;
    cout << "? " << a.size() << endl;
    for(auto x: a)
        cout << x+1 << " ";
    cout << endl;
    int m;
    cin >> m;
    if( m == -1 ) { 
        cout << 1/0 << endl;
    }
    return m;
}

int gg(vector<int> a, int v) { 
    int r = ask(a);
    a.push_back(v);
    return ask(a) - r;
}

vector<int> get(vector<int>& a, int xl, int xr) { 
    vector<int> r;
    for(int i = xl ; i < xr; i++)
        r.push_back(a[i]);
    return r;
}

void add(int s, vector<int>& a, int xl, int xr, bool rep=false) {
    int deg = gg(get(a,xl,xr), s);
    if( deg == 0 ) return;
    if( xr - xl == 1 ) { 
        int v = a[xl];
        if( rep ) throw( v ); 
        c[s][v] = c[v][s] = 1;
        oth.erase(v);
        que.push_back(v);
        return;
    }
    int xm = (xl+xr)/2;
    add(s, a, xl, xm, rep);
    add(s, a, xm, xr, rep);
}

void solve() { 
    que.push_back(0);
    oth.erase(0);

    for(int t = 0; t < sz(que); t++ ) { 
        int s = que[t];
        vector<int> tmp;
        for(auto x: oth)
            tmp.push_back(x);

        add(s, tmp, 0, sz(tmp));
    }
}


int mark[maxN], col[maxN];

void dfs(int s, bool cc) { 
    mark[s] = true;
    col[s] = cc;
    for(int i = 0; i < n; i++) 
        if( c[s][i] && !mark[i] ) 
            dfs(i, cc^1);
}

vector<int> fail;
bool pr(int s, int t) { 
    mark[s] = true;
    if( s == t ) { 
        fail.push_back(s);
        return true;
    }
    for(int i = 0; i < n; i++) 
        if( c[i][s] && !mark[i] && pr(i, t) ) {
            fail.push_back(s);
            return true;
        }
    return false;
}

int main() {
    cin >> n;

    for(int i = 0; i < n;i++)
        oth.insert(i);

    solve();
    dfs(0, 0);

    vector<int> ans, b;
    for(int i = 0; i < n; i++)
        if( col[i] ) 
            ans.push_back(i);
        else
            b.push_back(i);

    int x = ask(ans), y = ask(b);
    if( x == 0 && y == 0 ) {
        cout << "Y " << ans.size() << endl;
        for(auto x: ans)
            cout <<x+1 << " ";
        cout << endl;
        return 0;
    }

    if( x == 0 ) 
        ans.swap(b);

    for(auto x: ans) {
        vector<int> tmp;
        for( auto y: ans ) 
            if( x != y ) 
                tmp.push_back(y);

        try { 
            add( x , tmp , 0 , sz(tmp) , 1 ); 
        } catch(int v) { 
            memset(mark, 0 , sizeof mark);
            pr(x, v);
            cout << "N " << fail.size() << endl;
            for(auto v:fail)
                cout << 1+v << " ";
            cout << endl;
            return 0;
        }
    }

    cout << "IMP" << endl;

    return 0;
}