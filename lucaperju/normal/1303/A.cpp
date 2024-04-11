#include <bits/stdc++.h>
using namespace std;
char v[103];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>v;
        n=strlen(v);
        int st=-2,dr=-3,cnt=0;
        for(i=0;i<n;++i)
        {
            if(v[i]=='1')
            {
                if(st==-2)
                    st=i;
                dr=i;
                ++cnt;
            }
        }
        cout<<dr-st+1-cnt<<'\n';
    }
    return 0;
}