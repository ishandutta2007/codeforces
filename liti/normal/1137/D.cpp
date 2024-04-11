//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = -1;

int move(int x) { 
    cout << "next "; 
    if( x == -1 ) 
        cout << "0 1";
    else if( x < 2 ) 
        cout << x; 
    else
        cout << "0 1 2 3 4 5 6 7 8 9"; 
    cout << endl;
    cout.flush();

    int k;
    cin >> k; 
    string s;
    for(int i = 0; i < k; i++)
        cin >> s;
    return k;
}


int main(){
    for(int c = 1; ; c++) {
        move(-1);
        int v = move(1); 

        if( v == 2 ) {
            while( true ) { 
                int k = move(2);
                if( k == 1 ) {
                    cout << "done" << endl;
                    cout.flush();
                    return 0;
                }
            }
        }
    }

    return 0;
}