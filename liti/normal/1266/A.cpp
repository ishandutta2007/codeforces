//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define F first
#define S second 

const int N = -1; 

int main() { 
    int n; 
    cin >> n; 
    while(n--) { 
        string s; 
        cin >> s; 
        bool hasZ = false;
        bool hasE = false;
        int sum = 0; 

        for(auto x : s) { 
            int d = x - '0'; 
            if( !hasZ && d == 0 ) hasZ = true; 
            else if( d % 2 == 0 ) hasE = true; 
            sum = (sum + d) % 3; 
        }

        if( sum % 3 == 0 && hasZ && hasE ) 
            cout << "red" << endl; 
        else
            cout << "cyan" << endl;
    }

}