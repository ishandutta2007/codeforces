#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define DB(x) cout << #x << " " << x << endl
#define MP make_pair
#define wait system("pause")

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MAXN = (int)1e5 + 10;

int diff(char a, char b)
{
    int A = a - 'a';
    int B = b - 'a';
    if (A > B) swap(A, B);
    return min(B - A, A + 26 - B);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        
    int n, p; cin >> n >> p;
    string s; cin >> s;
    
    int ans = 0;
    int m = 1000000, M = -1;
    for (int i = 0; i < n / 2; ++i)
    {
        if (s[i] != s[s.length() - i - 1]){
           m = min(m, i);
           M = max(M, i);
        }
        ans += diff(s[i], s[s.length() - i - 1]);
    }
    
    p = min(p, (int)s.length() - p + 1);
    
    if (M == -1)
       ans = 0;
    else if (2 * p == n + 1)
       ans += p - m - 1;
    else
    {
        p--;
        if (M <= p)
           ans += p - m;
        else if (p <= m)
           ans += M - p;
        else
            ans += M - m + min(M - p, p - m);            
    }
    
    cout << ans << endl;
    //wait;
    
    return 0;
}
/*
7 2
ybxdcba
*/