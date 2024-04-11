#include <bits/stdc++.h>
using namespace std;
int st[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int k=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            if(a==1)
                st[++k]=1;
            else
            {
                while(st[k]!=a-1)
                    --k;
                ++st[k];
            }
            for(j=1;j<k;++j)
            {
                cout<<st[j]<<'.';
            }
            cout<<st[k]<<'\n';
        }
    }
    return 0;
}