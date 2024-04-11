//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define F first
#define S second 

const int N = 500 + 10; 

int vr[N], vc[N]; 

int main() { 
    int r, c; 
    cin >> r >> c; 

    if( r == c && r == 1 ) { 
        cout << 0 << endl; 
        return 0; 
    }

    if( r < c ) { 
        for(int i = 0 ; i < r; i++) 
            vr[i] = i+1; 
        for(int i = 0; i < c; i++) 
            vc[i] = r + i + 1; 
    } else { 
        for(int i = 0 ; i < c; i++) 
            vc[i] = i+1; 
        for(int i = 0; i < r; i++) 
            vr[i] = c + i + 1; 
    }

    for(int i = 0; i < r; i++) { 
        for(int j = 0; j < c; j++) 
            cout << vr[i] * vc[j] << ' ';
        cout << '\n'; 
    }
}