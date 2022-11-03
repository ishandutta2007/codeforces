#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
map<int , int> mp;
set<int> st;
int a , cnt1 , cnt2 , _min = 1e9 + 1 , _max = -1;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(a < _min)
        {
            cnt1 = 1;
            _min = a;
        }
        else if(a == _min)
            cnt1++;
        if(a > _max)
        {
            cnt2 = 1;
            _max = a;
        }
        else if(a == _max)
            cnt2++;
    }
    cout << max(n - cnt1 - cnt2 , 0);
}