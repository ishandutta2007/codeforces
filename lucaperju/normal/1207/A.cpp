#include <bits/stdc++.h>

using namespace std;
const int mod=998244853;
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,i,j,cnt=0,m,p,h,c,a,b;
    cin>>n;
    while(n--)
    {
        cin>>p>>h>>c;
        cin>>a>>b;
        int s=0;
        if(a>=b)
        {
            s+=a*(min(p/2,h));
            int cat=min(p/2,h);
            p-=2*cat;
            h-=cat;
            //-
            s+=b*(min(p/2,c));
            cat=min(p/2,c);
            p-=2*cat;
            c-=cat;
        }
        else
        {
            s+=b*(min(p/2,c));
            int cat=min(p/2,c);
            p-=2*cat;
            c-=cat;
            //-
            s+=a*(min(p/2,h));
            cat=min(p/2,h);
            p-=2*cat;
            h-=cat;
        }
        cout<<s<<'\n';
    }
    return 0;
}