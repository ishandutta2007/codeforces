#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int maxn = 1e5+20;
int main()
{
    int n,t;
    cin >> n >> t;
    string s;
    cin >> s;
    for(int ii =0 ; ii < t; ii++)
    for(int i=0 ; i < n-1 ;i++)
    {
        if(s[i] == 'B' && s[i+1] == 'G')
        {
            s[i] = 'G';
            s[i+1] = 'B';
            i++;
        }
    }
    cout << s;
}