//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii;

int a[256]; 

int main() { 
    a['T'] = 4;
    a['C'] = 6;
    a['O'] = 8;
    a['D'] = 12; 
    a['I'] = 20; 
    int n; cin >> n; 
    int sum = 0; 
    for( int i = 0 ; i < n ; i++ ) { 
        string s; cin >> s; 
        sum += a[s[0]]; 
    }
    cout << sum << endl;
}