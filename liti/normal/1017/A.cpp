//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

const int maxN = 1000 + 10;

typedef pair<int,int> pii; 
pii a[maxN];

bool cmp(pii a, pii b) { 
    if( a.first != b.first ) 
        return a.first > b.first; 
    return a.second < b.second;
}


int main() {
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){ 
        int x, y, z, w;
        cin >> x >> y >> z >> w; 
        int s = x + y + z + w; 
        a[i] = { s , i }; 
    }

    sort(a, a + n, cmp); 
    for(int i = 0; i < n ;i++) 
        if( a[i].second == 0 ) { 
            cout << i + 1 << endl;
            return 0;
        }

    return 0;

}