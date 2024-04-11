#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

typedef pair<int, int> pii;

int n;
pii a[1005];

int main() {
    ios :: sync_with_stdio(false);
    
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i].first; a[i].second = i+1;
    }
    
    sort(a, a + n);
    
    cout << a[n-1].second << ' ' << a[n-2].first << '\n';
    return 0;
}