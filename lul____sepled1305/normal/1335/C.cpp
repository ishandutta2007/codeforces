#include<bits/stdc++.h>
using namespace std;
int t,i,j,n,k,ans,siz,divv,curr;

int main()
{
    cin>>t;
    for(i=0;i<t;i++)
    {
        divv=1; siz=1; curr=1;
        cin>>n;
        vector<int> v;
        for(j=0;j<n;j++)
        {
            cin>>k;
            v.push_back(k);
        }
        sort(v.begin(),v.end());
        for(j=1;j<n;j++)
        {
            if(v[j-1]==v[j])
            {
                curr++;
                if(curr>siz)
                    siz=curr;
            }
            else
            {
                divv++;
                curr=1;
            }
        }
        if(divv>siz)
            cout<<siz<<"\n";
        else if (divv==siz)
            cout<<siz-1<<"\n";
        else
            cout<<divv<<"\n";
    }
    return 0;
}