//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int,int> pii; 

int cnt[256]; 

int main() { 
    string s; cin >> s; 
    for( auto x : s ) 
        cnt[x] ++;
    
    int mn = 1000 * 1000 + 100; 
    string t = "Bulbasaur";
    for( auto x : t ) { 
        int count = 0; 
        for( auto y : t ) 
            if( x == y ) count++; 
        mn = min( mn , cnt[x] / count ) ; 
    }
    cout << mn << endl;
}