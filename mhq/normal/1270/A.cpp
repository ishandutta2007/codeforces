#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i < k1; i++) 
    {
        if (a[i] == n) {
            cout << "YES"<<endl;
            return;
        }
    }
    cout << "NO"<<endl;;
}

int main() {
    int t;
    cin>>t;
    for (int i = 0; i<t; i++) solve();
}