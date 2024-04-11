#include <bits/stdc++.h>
using namespace std;
char v[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t,m,k,n1;
    cin>>t;
    while(t--)
    {
        cin>>(v+1);
        n=strlen(v+1);
        int vlc=-1;
        long long s=0;
        int sc=0;
        for(i=1;i<=n;++i)
        {
            if(v[i]=='+')
                ++sc;
            else
                --sc;
            if(sc==vlc)
            {
                --vlc;
                s+=i;
            }
        }
        cout<<s+n<<'\n';
    }
    return 0;
}