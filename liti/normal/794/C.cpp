//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii;

int cnt[2][26];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string a, b; 
    cin >> a >> b; 
    int n = a.size(); 
    sort( a.begin() , a.end() ); 
    sort( b.begin() , b.end() ); 
    reverse( b.begin() , b.end() ); 

    for( int i = 0 ; i < (n+1)/2 ; i++ ) 
        cnt[0][a[i]-'a']++;
    for( int i = 0 ; i < n/2 ; i++ ) 
        cnt[1][b[i]-'a']++;

    int len = n;
    int st = 0;
    string s = "";
    for( int i = 0 ; i < n ; i++ ) 
        s += '?'; 

    for( int i = 0 ; i < n ; i ++ ) { 
        int f[] = { -1 , -1 }, 
            l[] = { -1 , -1 }; 

        for( int t = 0 ; t < 2 ; t++ ) 
            for( int k = 0 ; k < 26 ; k++ ) { 
                if( cnt[t][k] && f[t] == -1 ) 
                    f[t] = k;
                if( cnt[t][k] ) l[t] = k;
            }

        if( i % 2 == 0 ) { 
            if( f[0] >= l[1] ) { 
                cnt[0][l[0]]--; 
                s[--len] = 'a' + l[0]; 
            } else { 
               cnt[0][f[0]]--;
               s[st++] = 'a' + f[0];  
            }
        } else { 
            if( l[1] <= f[0] ) { 
                cnt[1][f[1]]--; 
                s[--len] = 'a' + f[1]; 
            } else { 
                cnt[1][l[1]]--;
                s[st++] = 'a' + l[1]; 
            }
        }
    }
    cout << s << endl;
}