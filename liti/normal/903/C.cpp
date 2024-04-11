#include <bits/stdc++.h>
using namespace std; 

const int maxN = 5000 + 10; 

multiset<int> a;

int main() { 
    int n; 
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a.insert(v);
    }
    
    int ans = 0;
    
    while(a.size()) {
        ans++;
        int current = *a.begin();
        a.erase(a.begin());
        
        while(a.upper_bound(current) != a.end()) {
            current = *a.upper_bound(current);
            a.erase(a.find(current));
        }
    }
    
    cout << ans << endl;
}