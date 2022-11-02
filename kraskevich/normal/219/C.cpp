#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cassert>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>
#define ALL(x) x.begin(), x.end()
#define PB push_back

typedef long long i64;
const double eps = 1e-7;
const int inf = (int)1e9;



//---------------------------------------//
//Reading and printing arrays and vectors//
template<class T> void read(vector<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        cin >> a[i];
}

template<class T> void read(T a[], int n)
{
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

template<class T> void print(vector<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    cout << "\n";
}

template<class T> void print(T a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

void wait()
{
    int w;
    cin >> w;
}
//-----------------------------------------//

const int N = 5 * 100 * 1000;

int dp[N][26];
int no[N][26];
char c[N][26];
char prev[N][26];

string s;

void rec(int pos, int cur)
{
    if (pos < 0)
        return;
    rec(pos - 1, prev[pos][cur]);
    cout << char('A' + cur);
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int k, n;
    cin >> n >> k;
    cin >> s;
    
    if (s.length() == 1)
    {
        cout << 0 << endl << s;
        return 0;
    }
        
    
    for (int i = 0; i < n; ++i)
        s[i] -= 'A';
    
    for (int i = 0; i < k; ++i)
        dp[0][i] = 1;
    dp[0][s[0]] = 0;
    
    for (int i = 0; i < k; ++i)
        no[0][i] = 0, c[0][i] = s[0];
    no[0][s[0]] = 1;
    c[0][s[0]] = (s[0] ? 0 : 1);
    
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < k; ++j)
            no[i][j] = dp[i][j] = inf;
    
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            int inc = 0;
            if (j != s[i])
                ++inc;
            
            dp[i][j] = no[i - 1][j] + inc;
            prev[i][j] = c[i - 1][j];
        }
        
        int pm[k], sm[k], cpm[k], csm[k];
        for (int j = 0; j < k; ++j)
            pm[j] = sm[j] = inf;
            
        for (int j = 0; j < k; ++j)
        {
            if (j)
            {
                pm[j] = pm[j - 1];
                cpm[j] = cpm[j - 1];
            }
            if (dp[i][j] < pm[j])
            {
                pm[j] = dp[i][j];
                cpm[j] = j;
            }
        }
        
        for (int j = k - 1; j >= 0; --j)
        {
            if (j != k - 1)
            {
                sm[j] = sm[j + 1];
                csm[j] = csm[j + 1];
            }
            if (dp[i][j] < sm[j])
            {
                sm[j] = dp[i][j];
                csm[j] = j;
            }
        }
        
        for (int j = 0; j < k; ++j)
        {
            if (j != k - 1 && no[i][j] > sm[j + 1])
            {
                no[i][j] = sm[j + 1];
                c[i][j] = csm[j + 1];
            }
            if (j != 0 && no[i][j] > pm[j - 1])
            {
                no[i][j] = pm[j - 1];
                c[i][j] = cpm[j - 1];
            }
        }
    }
    
    int res = inf, cres = 0;
    for (int j = 0; j < k; ++j)
        if (dp[n - 1][j] < res)
        {
            res = dp[n - 1][j];
            cres = j;
        }
    
    cout << res << endl;
    
    rec(n - 1, cres);
    
            
    return 0;
}