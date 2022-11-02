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
        int n,k,i,counti = 0,m;
        long long sum =0;
        cin>>n>>k;
        vector<int> a,w;
        for(i=0;i<n;i++)
            cin>>m, a.push_back(m);
        sort(a.begin(),a.end());
        for(i=0;i<k;i++)
            cin>>m, w.push_back(m);
        sort(w.begin(),w.end(),greater<int>());
        while(w.back()==1)
        {
            sum+=2*a.back();
            a.pop_back();
            w.pop_back();
            k--;
        }
        i=0;
        while(counti<k)
        {
            sum+=a[i];
            i+=w[counti]-1;
            if(w[counti]==1)
                i++;
            counti++;
        }
        for(i=0;i<k;i++)
        {
            sum+=a.back();
            a.pop_back();
        }
        cout<<sum<<"\n";
    }
    return 0;
}