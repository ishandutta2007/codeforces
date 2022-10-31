//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 26 + 2;

vector<int> c[maxN]; 

int main() {
    string s; 
    cin >> s;
    for( int i = 0 ; i < int(s.size()) ; i++ ) 
        c[s[i]-'a'].push_back(i); 
    int ans = s.size(); 
    for( int i = 0 ; i < 26 ; i++ ) 
        if( c[i].size() ) { 
            int tmp = c[i][0] + 1; 
            for( int j = 1 ; j < int(c[i].size()) ; j++ ) 
                tmp = max(tmp, c[i][j] - c[i][j-1]);
            tmp = max(tmp, int(s.size()) - c[i][int(c[i].size())-1]);
            ans = min(ans, tmp);
        }
    cout << ans << endl;
}