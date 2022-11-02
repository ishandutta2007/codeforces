#include <bits/stdc++.h>

using namespace std;

const int N = 4444;

bitset<N> a[N];
int n;

void do_elimination() {
    for (int row = 0; row < n; row++) {
        int p = row;
        while (!a[p][row])
            p++;
        if (row != p)
            swap(a[row], a[p]);
        for (int i = 0; i < n; i++)
            if (i != row && a[i][row])
                a[i] ^= a[row];
    }    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        a[i][i + n] = true;
    vector<int> x(m);
    vector<int> y(m);
    for (int i = 0; i < m; i++) {   
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--; 
        a[x[i]][y[i]] = true;   
    } 
    do_elimination();
    for (int i = 0; i < m; i++) {
        cout << (a[y[i]][x[i] + n] ? "NO" : "YES") << "\n";    
    }
}