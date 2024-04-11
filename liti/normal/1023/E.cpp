//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

char ans[1000];

int main() {
    int n;
    cin >> n; 

    int x = 1 , y = 1; 
    
    for(int i =0 ; i < n - 1; i++)
        if( x + 1 <= n ) { 
            cout << "? " << x + 1 << " " << y << " " << n << " " << n << endl;
            cout.flush();
            string s;
            cin >> s; 
            if( s == "YES" ) {
                ans[i] = 'D';
                x++;
            } else {
                y++;
                ans[i] = 'R';
            }
        } else {
            y++;
            ans[i] = 'R';
        }

    x = n, y = n;
    for(int i = 2 * n - 3 ; i >= n - 1 ; i-- ) { 
        if( y - 1 >= 0 ) { 
            cout << "? " << "1 1 " << x << " " << y - 1 << endl;
            cout.flush();
            string s;
            cin >> s;
            if( s == "YES" ) { 
                ans[i] = 'R';
                y--;
            } else { 
                ans[i] = 'D';
                x--;
            }
        } else { 
            x--;
            ans[i] = 'D';
        }
    }

    cout << "! " ;
    for(int i = 0 ; i < 2 * n - 2 ; i++)
        cout << ans[i];
    cout << endl;
    cout.flush();

    return 0;
}