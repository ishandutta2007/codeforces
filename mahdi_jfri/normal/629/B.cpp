#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e3+20;
int l[maxn],r[maxn];
char g[maxn];
int ans=0;
int main()
{
    int n;
    cin >> n;
    for(int i=0; i < n ;i++)
    {
        cin >> g[i] >> l[i] >> r[i];
    }
    for(int i=0; i < 367; i++)
    {
        int f=0,m=0;
        for(int j=0; j < n; j++)
        {
            if(i >= l[j] && i<=r[j])
            {
                if(g[j] == 'M')
                    m++;
                else
                    f++;
            }
        }
        ans=max(ans,min(f,m));
    }
    cout << ans*2;
}