#include<bits/stdc++.h>
using namespace std;
int n,i,k,m,more,lessi;
char c;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    cin>>k;
    for(i=1;i<=k;i++)
    {
        cin>>c>>m>>n;
        if(c=='+')
        {
            if(m>n)
            {
                if(more<m)
                {
                    more=m;
                }
                if(lessi<n)
                {
                    lessi=n;
                }
            }
            else
            {
                if(more<n)
                {
                    more=n;
                }
                if(lessi<m)
                {
                    lessi=m;
                }
            }
        }
        else
        {
            if(m>n)
            {
                if(m>=more && n>=lessi)
                {
                    cout<<"YES\n";
                }
                else cout<<"NO\n";

            }
            else
            {
                if(n>=more && m>=lessi)
                {
                    cout<<"YES\n";
                }
                else cout<<"NO\n";
            }
        }
    }
    return 0;
}