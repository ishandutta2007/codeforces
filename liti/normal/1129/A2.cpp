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

const int N = 5000 + 10;

int a[N]; 
vector<int> c[N]; 

int n, m;
int cmpV; 

bool cmp(int x, int y) { 
    return (x - cmpV + n) % n > (y - cmpV + n) % n; 
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++) { 
        int x, y;
        cin >> x >> y;
        x--; y--; 
        c[x].push_back(y); 
    }
    for(int i = 0; i < n; i++) {
        cmpV = i; 
        sort(c[i].begin(), c[i].end(), cmp); 
    }

    for(int i = 0; i < n; i++) {
        ll ans = 0; 
        for(int t = 0; t < n; t++) { 
            int j = (i+t) % n; 

            if( c[j].size() ) { 
                int last = c[j][sz(c[j])-1]; 
                int k = sz(c[j]) - 1;
                ans = max(ans, t + 1ll * k * n + (last - j + n) % n);
            }
        }
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}