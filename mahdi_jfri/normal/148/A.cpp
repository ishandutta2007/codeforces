#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int maxn = 1e5+20;
int a[4];
bool isp[maxn];
int res;
int main()
{
    int n;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!isp[i])
        {
            for(int j = 0 ; j < 4 ; j++)
                if(!(i%a[j]))
                {
                    isp[i]=1;
                    res++;
                    break;
                }
        }
    }
    cout << res;
}