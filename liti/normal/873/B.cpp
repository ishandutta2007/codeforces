//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 1000 * 100 + 10; 
int first[maxN*2];

int main() { 
    int n ; cin >> n;

    string s;
    cin >> s;

    int cnt = 0; 
    memset(first, -1 , sizeof first);
    first[cnt+maxN] = 0;
    int ans = 0;
    for(int i = 0 ; i < n ; i++ ) { 
        cnt += ( s[i] == '0' ? 1 : -1 ); 
        if( first[cnt+maxN] == -1 ) 
            first[cnt+maxN] = i + 1; 
        else
            ans = max(ans, i + 1 - first[cnt+maxN] ); 
    }
    cout << ans << endl;
}