//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 70 * 1000 + 100; 

unordered_map<int,int> cnt[10]; 
unordered_map<int,int> cnt2[10];
string a[maxN]; 
int val[maxN][10]; 

int main() { 
    int n; cin >> n; 
    for( int i = 0 ; i < n ; i++ ) {
        cin >> a[i];
        for( int first = 0 ; first < 9 ; first++ ) { 
            int v = 0;
            for( int second = first ; second < 9 ; second++ ) { 
                v = v * 10 + a[i][second] - '0';
                if( !cnt2[second-first].count(v) )
                    cnt2[second-first][v] = 1+i;
                cnt[second-first][v] = 1+i;
            }
        }
    }

    for( int i = 0 ; i < n ; i++ ) { 
        bool canDo = false;
        for( int len = 1 ; len < 10 && !canDo ; len++ ) { 
            for( int first = 0 ; first < 10 - len && !canDo ; first++ ) { 
                int second = first + len - 1; 
                val[i][first] = val[i][first] * 10 + a[i][second] - '0'; 
                if( cnt[second-first][val[i][first]] == 1+i && cnt2[second-first][val[i][first]] == 1+i ) { 
                    cout << a[i].substr( first , len ) << '\n'; 
                    canDo = true;
                }
            }
        }
    }
}