#include <bits/stdc++.h>
using namespace std;
char v[500005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,k,i,j;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    j=1;
    int lst=1;
    for(i=2;i<=n;++i)
    {
        if(v[i]<v[j])
        {
            j=1;
            lst=i;
        }
        else if(v[i]==v[j])
            ++j;
        else
            break;
    }
    j=1;
    while(k--)
    {
        cout<<v[j];
        ++j;
        if(j==lst+1)
            j=1;
    }
    return 0;
}