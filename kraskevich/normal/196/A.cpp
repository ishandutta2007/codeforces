#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

typedef long long i64;
#define MP make_pair
#define F first
#define S second
#define FORN for(int i = 0; i < n; ++i)
#define PB push_back

const int N = 100000;
int cnt[N][26];
           
int main()
{
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < 26; ++j)
            cnt[i][j] = 0;
            
    string s;
    cin >> s;
    
    for(int i = 0; i < s.length(); ++i)
        for(int j = 0; j < 26; ++j)
            if(s[i] == char(j + 'a'))
                cnt[i][j] = (i ? cnt[i - 1][j] + 1 : 1);
            else
                cnt[i][j] = (i ? cnt[i - 1][j] : 0);
    
    for(int i = 0; i < s.length(); ++i)
    {
        char c = s[i];
        bool need = true;
        
        for(int j = c - 'a' + 1; j < 26; ++j)
            if(cnt[s.length()- 1][j] != cnt[i][j])
                need = false;
        
        if(need)
            cout << c;
    }
    
    cout << endl;
    
    cin >> s;
    return 0;
}