#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    
    int n, m;
    
    cin >> n >> m;
    
    vector< string > a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    
    int sum = 0;
    
    for(int i = 0;i < n;i++) sum += count(a[i].begin(), a[i].end(), '*');
    
    vector< int > str(n), col(m);
    
    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) {
        if(a[i][j] == '*') str[i]++, col[j]++;
    }
    
    for(int t, i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            t = str[i] + col[j] - (a[i][j] == '*'?1 : 0);
            if(t == sum) {
                cout << "YES\n" << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
        }
    }
    
    cout << "NO\n";
    
    return 0;
}