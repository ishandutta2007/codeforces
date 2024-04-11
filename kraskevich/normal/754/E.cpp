#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 401;

bitset<N> rc[N][N][26];
string s[N];
string q[N];
int n, m;
int r, c;

void init() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c = s[i][j];
            for (int s = 0; s < m; s++)
                rc[i][s][c - 'a'].set((j - s + m) % m);        
        }
}

bitset<N> solve(int st) {
    bitset<N> res;
    res.set();
    for (int i = 0; i < r; i++) {
        int row = (st + i) % n;
        for (int j = 0; j < c; j++)
            if (q[i][j] != '?') 
                res &= rc[row][j % m][q[i][j] - 'a'];   
    }  
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> q[i];
    init();
    for (int i = 0; i < n; i++) {
        auto b = solve(i);
        for (int j = 0; j < m; j++)
            if (b[j])
                cout << '1';
            else
                cout << '0';
        cout << "\n";    
    }
}