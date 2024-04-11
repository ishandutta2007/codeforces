
#include <bits/stdc++.h>

using namespace std;
pair<int,int>m2[10][10];
pair<int,int>m3[10][10][10];
char v[1003];
int dp[1003];
struct ura
{
    int a,b,c;
};
vector<ura>rz;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n,l=1,r=n-1,cat=0;
        cin>>n;
        r=n-1;
        while(l<r)
        {
            int mid=(l+r)/2;
            int kc=n-1-r;
            cout<<"+ "<<kc+n-(kc+mid)-1<<'\n';
            int a;
            cin>>a;
            cout.flush();
            if(a==cat)
            {
                l+=kc+n-(kc+mid)-1;
                r=mid+kc+n-(kc+mid)-1;
                continue;
            }
            else if(a==cat+1)
            {
                ++cat;
                l=0;
                r=r+kc-(kc+mid)-1;
                continue;
            }
            assert(0);
        }
        cout<<"! "<<cat*n+l<<'\n';
    }

    return 0;
}