#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, ans;
int flag[1010101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, i, j, temp=0, t6=10000000, a1, a2;
    long double u, d, x;
    cin>>t;
    while(t--)
    {
        set<int> ok1, ok2, ok3, ok4;
        cin>>n;
        int cnt[10101]= {0, };
        for(i=0; i<n; i++)
        {
            cin>>temp;
            cnt[temp]++;
            if(cnt[temp]==4) ok4.insert(temp);
            else if(cnt[temp]==2) ok2.insert(temp);
        }
        if(!ok4.empty())
        {
            ans=(*ok4.begin());
            cout<<ans<<' '<<ans<<' '<<ans<<' '<<ans<<'\n';
            continue;
        }
        else
        {
            set<int>::iterator it=ok2.begin();
            u=a1=(*it);
            it++;
            d=a2=(*it);
            x=u/d;
            while(1)
            {
                u=(*it);
                it++;
                if(it==ok2.end()) break;
                d=(*it);
                if(u/d>x)
                {
                    a1=u;
                    a2=d;
                    x=u/d;
                }
            }
            cout<<a1<<' '<<a1<<' '<<a2<<' '<<a2<<'\n';
        }

    }

}