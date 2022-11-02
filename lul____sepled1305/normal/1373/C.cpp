/**Ithea is a nice girl.**/
#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
    {
        long long n,i,j=0,local_min = 0,ans=0;
        string s;
        cin>>s;
        n = s.size();
        long long pref_sum[n];
        for(i=0;i<n;i++)
        {
            if(s.at(i)=='+')
                j++;
            else
                j--;
            pref_sum[i] = j;
        }
        for(i=0;i<n;i++)
        {
            if(pref_sum[i]<local_min)
            {
                ans+= (local_min - pref_sum[i])*(i+1);
                local_min = pref_sum[i];
            }
        }
        ans+=n;
        cout<<ans<<"\n";
    }
    return 0;
}