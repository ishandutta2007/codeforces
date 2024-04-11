//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int,int> pii; 

const int maxN = 100 * 1000 + 10; 

int cnt[maxN]; 

int main() { 
    ios::sync_with_stdio(false); cin.tie(0); 
    int n; 
    cin >> n;
    int ans = 1; 
    for( int i = 0 ; i < n ; i++ ) { 
        int x; cin >> x; 
        cnt[x]++; 
    }
    for( int i = 2 ; i < maxN ; i++ ) { 
        int sum = 0;
        for( int j = i ; j < maxN ; j += i ) 
            sum += cnt[j]; 
        ans = max( ans , sum ); 
    }

    cout << ans << endl;
}