/**
    Chtholly Nota Seniorious
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
int T;

void solve()
{
    int n,m,i;
    cin>>n>>m;
    int a[n],b[m];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<m;i++)
        cin>>b[i];
    long long sum = 0;
    sort(a,a+n,greater<int>());
    int pointer = 0;
    for(i=0;i<n;i++)
    {
        a[i]--;
        if(a[i] > pointer)
        {
            sum += b[pointer];
            pointer++;
        }
        else
        {
            sum += b[a[i]];
        }
    }
    cout<<sum<<endl;
}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
        solve();
    return 0;
}