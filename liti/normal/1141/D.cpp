//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = 150*1000 + 100;

vector<int> p[2][26]; 

vector<pii> ans; 
vector<int> cnt[2];

int main(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b; 

    for(int i = 0; i < n; i++) {
        if( a[i] != '?' ) 
            p[0][a[i]-'a'].pb(i); 
        else
            cnt[0].pb(i);
        if( b[i] != '?' )
            p[1][b[i]-'a'].pb(i); 
        else
            cnt[1].pb(i);
    }

    for(int i = 0; i < 26; i++) { 
        int mn = min( sz(p[0][i]), sz(p[1][i]) ); 
        for(int j = 0; j < mn; j++) { 
            ans.pb( pii( p[0][i].back(), p[1][i].back() ) );
            p[0][i].pop_back();
            p[1][i].pop_back();
        }

        while( p[0][i].size() && cnt[1].size() ) { 
            ans.pb( pii( p[0][i].back(), cnt[1].back() ) );
            p[0][i].pop_back();
            cnt[1].pop_back();
        }
        while( p[1][i].size() && cnt[0].size() ) { 
            ans.pb( pii( cnt[0].back(), p[1][i].back() ) );
            cnt[0].pop_back();
            p[1][i].pop_back();
        }
    }
    while( cnt[0].size() && cnt[1].size() ) { 
        ans.pb( pii( cnt[0].back(), cnt[1].back() ) ); 
        cnt[0].pop_back();
        cnt[1].pop_back();
    }
    cout << sz(ans) << '\n';
    for(auto x : ans) 
        cout << x.F + 1 << ' ' << x.S + 1 << '\n';

    return 0;
}