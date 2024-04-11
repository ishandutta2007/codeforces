#include <bits/stdc++.h>
#define ff(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX=1e5+5, INF=1e9;

int n, m;
vector <string> s;
int a[] = {0,0,1,1}, b[] = {0,1,1,0};

void init(void) {
    cin >> n >> m;
    s.assign(n, string());
    ff(i, 0, n - 1) cin >> s[i];
}

void process(void) {
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m - 1; j++) {
        bool f[26] = {0};
        ff(k, 0, 3) f[s[i+a[k]][j+b[k]] - 'a'] = 1;
        if(f[0] && f[5] && f[2] && f[4]) res++;
    }
    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}