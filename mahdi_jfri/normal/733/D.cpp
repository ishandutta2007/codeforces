#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 20;
map<pair<int, int> , int> mp;
int a[maxn] , b[maxn] , c[maxn];
ll _max = -1;
ll _min;
int jj = -1 , jjj = -1;
void kar(int aa , int bb , int cc , int i)
{
    if(mp.find({aa , bb}) == mp.end())
        mp[{aa , bb}] = i;
    else
    {
        int j = mp[{aa , bb}];
        if(j == i)
            return;
        if(aa == a[j])
        {
            if(bb == b[j])
            {
                _min = min(aa , min(bb , cc + c[j]));
                mp[{aa , bb}] = ((cc > c[j])? i:j);
            }
            else if(bb == c[j])
            {
                _min = min(aa , min(bb , cc + b[j]));
                mp[{aa , bb}] = ((cc > b[j])? i:j);
            }
        }
        else if(aa == b[j])
        {
            if(bb == c[j])
            {
                _min = min(aa , min(bb , a[j] + cc));
                mp[{aa , bb}] = ((cc > a[j])? i:j);
            }
            else if(bb == a[j])
            {
                _min = min(aa , min(bb , c[j] + cc));
                mp[{aa , bb}] = ((cc > c[j])? i:j);
            }
        }
        else if(aa == c[j])
        {
            if(bb == a[j])
            {
                _min = min(aa , min(bb , b[j] + cc));
                mp[{aa , bb}] = ((cc > b[j])? i:j);
            }
            else if(bb == b[j])
            {
                _min = min(aa , min(bb , a[j] + cc));
                mp[{aa , bb}] = ((cc > a[j])? i:j);
            }
        }
        if(_min > _max)
        {
            _max = _min;
            jj = j;
            jjj = i;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        if(min(a[i] , min(b[i] , c[i])) > _max)
        {
            _max = min(a[i] , min(b[i] , c[i]));
            jj = i;
            jjj = -1;
        }
        kar(a[i] , b[i] , c[i] , i);
        kar(a[i] , c[i] , b[i] , i);
        kar(b[i] , a[i] , c[i] , i);
        kar(b[i] , c[i] , a[i] , i);
        kar(c[i] , a[i] , b[i] , i);
        kar(c[i] , b[i] , a[i] , i);
    }
    if(jjj == -1 || jj == jjj)
        cout << 1 << endl << jj + 1;
    else
    {
        cout << 2 << endl << jj + 1 << " " << jjj + 1;
        return 0;
    }
}