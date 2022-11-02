/**Ithea is a nice girl.**/
#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    while(T--)
    {
        long long n,i,j,val1=0,val2=0,sum = 0;
        cin>>n;
        long long a[n];
        vector<long long> pref1,pref2;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(i%2==0)
                sum+=a[i];
        }
        long long cur1 = 0;
        long long cur2 = 0;
        for(i=0;i<n;i++)
        {
            if(i%2==1)
                cur1+=a[i]-a[i-1],pref1.push_back(cur1);
            if(i%2==1 && i!=n-1)
                cur2+=a[i]-a[i+1],pref2.push_back(cur2);
        }
        long long mini = 0, maxi = -1e18-10;
        for(auto it: pref1)
        {
            if(it < mini)
                mini = it, maxi = -1e18-10;
            else if(it > maxi)
                maxi = it;
            val1 = max(val1,maxi-mini);
        }
        mini = 0, maxi = -1e18-10;
        for(auto it: pref2)
        {
            if(it < mini)
                mini = it, maxi = -1e18-10;
            if(it > maxi)
                maxi = it;
            val2 = max(val2,maxi-mini);
        }
        cout<<sum+max(val1,val2)<<"\n";
    }
    return 0;
}