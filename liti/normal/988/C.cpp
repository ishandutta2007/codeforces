//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii;

const int maxN = 2 * 100 * 1000 + 100;

map<int,pii> mp; 
vector<int> a[maxN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 

    int n;
    cin >> n;

    for( int i = 0 ; i < n ; i++ ) { 
        int k; cin >> k; 

        int sum = 0; 
        for( int j = 0 ; j < k ; j++ ) { 
            int x; cin >> x; 
            a[i].push_back(x); 
            sum += x; 
        }
        for( int j = 0 ; j < k ; j++ ) 
            if( mp.count( sum - a[i][j] ) ) { 
                cout << "YES" << endl;
                auto v = mp[sum-a[i][j]];
                cout << v.first+1 << " " << v.second+1 << endl;
                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
        for( int j = 0 ; j < k ; j++ ) 
            mp[sum - a[i][j]] = pii( i , j ); 
    }
    cout << "NO" << endl;
}