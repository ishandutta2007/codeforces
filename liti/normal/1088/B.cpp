//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii; 
const int maxN = 100 * 1000 + 10; 

int a[maxN * 2]; 

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i]; 
    sort(a, a + n); 
    n = unique( a , a + n ) - a; 
    fill( a + n , a + n + k , a[n-1] );
    int last = 0; 
    for(int i = 0; i < k; i++) {
        cout << a[i] - last << '\n';
        last = a[i]; 
    }

    return 0;
}