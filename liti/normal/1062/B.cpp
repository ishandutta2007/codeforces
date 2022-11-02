//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

map<int, int> mp;

int main() { 
    int n;
    cin >> n; 

    if( n == 1 ) { 
        cout << "1 0" << endl;
        return 0;
    }

    int m = n;

    int ans = 0; 
    int z = 1; 
    for(int i = 2; i <= n ; i++ )
        if( n % i == 0 ) { 
            int cnt = 0; 
            for( ; n % i == 0; cnt++ ) 
                n /= i; 
            mp[cnt]++;
            ans = max(ans, cnt);
            z *= i;
        }

    int t = 0; 
    while( (1<<t) < ans ) 
        t++;

    if( (1<<t) == ans && mp.size() == 1 ) 
        cout << z << " " << t << endl;
    else
        cout << z << " " << t + 1 << endl;
}