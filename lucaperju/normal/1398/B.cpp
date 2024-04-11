#include <bits/stdc++.h>
using namespace std;
int v[103];
char vc[103];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,d,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>vc;
        int n=strlen(vc);
        int cnt=0;
        j=0;
        for(i=0;i<n;++i)
        {
            if(vc[i]=='1')
                ++cnt;
            else
            {
                v[++j]=cnt;
                cnt=0;
            }
        }
        v[++j]=cnt;
        sort(v+1,v+j+1);
        n=j;
        int s=0;
        for(i=n;i>=1;i-=2)
        {
            s+=v[i];
        }
        cout<<s<<'\n';
    }
    return 0;
}