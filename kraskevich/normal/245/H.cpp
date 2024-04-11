#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
 
using namespace std;
 
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define F first
#define S second
#define WAIT int w; cin >> w;
#define ALL(x) x.begin(), x.end()


const int N = 5000;
int odd[N], even[N];
string s;

void calc()
{
    int n = s.length();
    
    for (int i = 0; i < n; ++i)
    {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r])
            --l, ++r;
        ++l;
        --r;
        odd[i] = i - l;
    }
    
    for (int i = 0; i < n - 1; ++i)
    {
        int l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r])
            --l, ++r;
        ++l;
        --r;
        even[i] = i - l;
    }
    
    /*for (int i = 0; i < n; ++i)
        cout << odd[i] << " " << even[i] << endl;*/
}

int sum[N][N];
bool f[N][N];

void init()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            sum[i][j] = 0;
    
    for (int l = 0; l < s.length(); ++l)
        for (int r = l; r < s.length(); ++r)
            if ((r - l) % 2 == 0)
            {
                int mid = (l + r) / 2;
                if (mid - l <= odd[mid])
                    sum[l][r] = 1;
            }
            else
            {
                int mid = (l + r) / 2;
                if (mid - l <= even[mid])
                    sum[l][r] = 1;
            }

        
    /*for (int i = 0; i < s.length(); ++i)
    {
        for (int j = 0; j < s.length(); ++j)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }*/
    
    for (int len = 2; len <= s.length(); ++len)
        for (int l = 0; l + len - 1 < s.length(); ++l)
        {
            int r = l + len - 1;
            sum[l][r] += (sum[l + 1][r] + sum[l][r - 1] - sum[l + 1][r - 1]);
        }
    
    
    /*for (int i = 0; i < s.length(); ++i)
    {
        for (int j = 0; j < s.length(); ++j)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }*/

}
        

 
int main()
{
    ios_base::sync_with_stdio(0);
    
   
    cin >> s;
    calc();
    init();
   
    int q;
    cin >> q;
    
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        
        --l;
        --r;
        
        cout << sum[l][r] << "\n";
    }  
    
    //WAIT;
    
    return 0;
}