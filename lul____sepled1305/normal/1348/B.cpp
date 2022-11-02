#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n=0,k=0,i=0,j=0,foun=0;
        vector<int> ori;
        cin>>n>>k;
        int hap[n+1];
        for(i=0;i<=n;i++)
            hap[i]=0;
        for(i=0;i<n;i++)
        {
            cin>>j;
            ori.push_back(j);
            if(hap[j]==0)
            {
                foun++;
                hap[j]=1;
            }
        }
        if(foun>k)
        {
            cout<<"-1\n";
            continue;
        }
        cout<<n*k<<"\n";
        for(i=0;i<n;i++)
        {
            int cur=0,last=0;
            for(j=0;j<=n;j++)
            {
                if(hap[j]==1)
                {
                    cout<<j<<" ";
                    cur++;
                    last=j;
                }
                if(cur<k && j==n)
                {
                    while(cur<k)
                    {
                        cout<<last<<" ";
                        cur++;
                    }
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}