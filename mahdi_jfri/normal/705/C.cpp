#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define j1 azinj[d]
const int maxn=3e5+20;
int a[maxn];
bool b[maxn];
deque<bool>dq;
deque <int> l[maxn];
ll res;
int c , d;
ll azinja;
ll azinj[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n , q;
    cin >> n >> q;
    for(int i = 0; i < q ; i++)
    {
        cin >> c >> d;
        if(c == 1)
        {
            d--;
            res++;
            l[d].push_back(dq.size());
            dq.push_back(0);
        }
        else if(c == 2)
        {
            d--;
            while(azinj[d] < l[d].size())
            {
                if(dq[l[d][j1]] == 0)
                {
                    res--;
                    dq[l[d][j1]]=1;
                }
                azinj[d]++;
            }
        }
        else
        {
            while(azinja < d)
            {
                if(dq[azinja] == 0)
                {
                    res--;
                    dq[azinja] = 1;
                }
                azinja++;
            }
        }
        cout << res << endl;
    }
}