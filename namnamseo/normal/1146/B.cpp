#include <bits/stdc++.h>
using namespace std;

#define FOR(i, x, n) for(ll i = x; i < n; i++) 
#define pb push_back
#define ll long long
#define hii cout << "hii" << endl
#define pii pair<int, int>
#define pll pair<ll, ll>
#define int ll
#define mpp make_pair
#define endl '\n'
#define ff first 
#define ss second
#define all(s) s.begin(), s.end()
#define fuck_you_scanf ios_base:: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define si size()


const int mod = 1e9 + 9;
const int N = 1000005;
const int MAX = 5000;
const int N1 = 1005;

int n, m;

int32_t main()
{
    fuck_you_scanf;
    string input;
    cin >> input;
    
    int n = input.si;
    
    string hey = "";
    
    int idx = n;
    
    FOR(i, 0, n)
    {
        if(input[i] != 'a')
        {
            hey += input[i];
        }
    }
    
    if(hey.si % 2 == 0)
    {
        string a = hey.substr(0, hey.si/2);
        string b = hey.substr(hey.si/2);
        
        // cout << a << " " << b;
        if(a == b)
        {
            int cnt = hey.si / 2;
            
            int cnt1 = 0;
            
            FOR(i, 0, n)
            {
                if(input[i] != 'a')
                {
                    cnt1++;
                }
                

                if(cnt1 > cnt)
                {
                    idx = i;
                    break;
                }
            }
            
        }
        else
        {
            cout << ":(";
            return 0;
        }
        
    }
    else
    {
        cout << ":(";
        return 0;
    }
    
    
    hey = "";
    
    FOR(i, 0, n)
    {
        if(input[i] != 'a' and i < idx)
        {
            hey += input[i];
        }
    }
    
    
    // cout << hey << endl;
    string b = input.substr(idx);
    
    if(hey == b)
    {
        cout << input.substr(0, idx);
    }
    else
    {
        cout << ":(";
        return 0;
    }
    
    
}