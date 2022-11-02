#include<bits/stdc++.h>
using namespace std;
long long a,b,q,lefti,righti,lcm,i,c,d,jack,ans;
int t;

int gcd(long long aa, long long bb)
{
    if(aa%bb == 0)
        return bb;
    else
        return gcd(bb, aa%bb);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    while(t--)
    {
        cin>>a>>b>>q;
        c=min(a,b);
        d=max(a,b);
        lcm = c*d/gcd(c,d);
        while(q--)
        {
            cin>>lefti>>righti;
            jack = righti-lefti+1;
            long long floorr, ceill;
            floorr = righti/lcm;
            ceill = (lefti+lcm)/lcm;
            if(floorr-ceill>=0)
            {
                ans = jack - d*(floorr-ceill);
                if(lefti%lcm < d)
                    ans-=d-lefti%lcm;
                ans-=min(righti%lcm+1,d);
            }
            else
            {
                if(righti%lcm<d)
                    ans = 0;
                else if(lefti%lcm<d)
                    ans = righti%lcm-d+1;
                else
                    ans = righti - lefti+1;
            }

            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}