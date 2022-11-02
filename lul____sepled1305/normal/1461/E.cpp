/** Ithea best girl **/

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int k,l,r,t,x,y;
    cin>>k>>l>>r>>t>>x>>y;
    //k = initial, l,r = boundary, t = days, x = reduction, y = addition
    if(k<l || k>r)
    {
        cout<<"No\n";
        return;
    }

    if(y < x)
    {
        if(k+y <= r)
            k+=y;
        int after_one = k-x-l;
        int reduction = x-y;
        if(after_one/reduction < t-1)
            cout<<"No\n";
        else
            cout<<"Yes\n";
        return;
    }
    if(y == x)
    {
        if(k+y <= r || k-y >= l)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        return;
    }
    if(y > x)
    {
        set<int> st;
        k-=l;
        r-=l;
        l=0;
        //cout<<k<<' '<<r<<' '<<l<<endl;
        int day = 0;
        bool pass = true;
        while(true)
        {
            //cout<<k<<endl;
            day+=k/x;
            //cout<<k<<' '<<l<<' '<<r<<' '<<day<<endl;
            k = k%x;
            if(day >= t)
                break;
            if(k + y > r)
            {
                pass = false;
                break;
            }
            else
            {
                if(st.count(k))
                    break;
                st.insert(k);
                k+=y;
            }
        }
        if(pass)
            cout<<"Yes\n";
        else
            cout<<"No\n";

    }

}

main()
{
    solve();
    return 0;
}