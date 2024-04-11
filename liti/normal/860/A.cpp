//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

string bad = "aeuoi";

bool gg(char ch) { 
    return find(bad.begin(), bad.end(), ch) == bad.end(); 
}

int main() { 
    string s; cin >> s; 
    int z = 0; 
    for( int i = 0 ; i < (int)s.size() ; i++ ) { 
        if( z < 2 ) { 
            cout << s[i];
            z++;
        } else { 
            if( gg(s[i]) && gg(s[i-1]) && gg(s[i-2]) && 
                    !( s[i] == s[i-1] && s[i] == s[i-2] ) ) { 
                cout << " "; 
                i--;
                z = 0; 
            } else
                cout << s[i]; 
        }
    }
}