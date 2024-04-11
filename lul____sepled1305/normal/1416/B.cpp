/** Ogiso Setsuna best girl **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int MOD = 1e9+7;
const int chtholly = 0;
int T;

struct mov
{
    int fi,se,th;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    while(T--)
    {
        int n,i,j,sum=0;
        cin>>n;
        int a[n+1];
        vector<mov> v;
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n;i++)
            sum+=a[i];

        if(sum%n != 0)
        {
            cout<<"-1\n";
            continue;
        }

        int des = sum/n;

        for(i=2;i<=n;i++)
        {
            if(a[i]%i == 0)
                v.push_back({i,1,a[i]/i});
            else
            {
                v.push_back({1,i,i - (a[i]%i)});
                a[i]+= (i-(a[i]%i));
                v.push_back({i,1,a[i]/i});
            }
        }

        for(i=2;i<=n;i++)
        {
            v.push_back({1,i,des});
        }

        cout<<v.size()<<"\n";
        for(auto it: v)
        {
            cout<<it.fi<<' '<<it.se<<' '<<it.th<<"\n";
        }
    }
    return chtholly;
}