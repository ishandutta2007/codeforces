#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    cin>>t;
    while(t--)
    {
        int n,k,i,b;
        cin>>n>>k;
        vector<int> convert;
        for(i=0;i<n;i++)
        {
            cin>>b;
            if(b<k) b=0;
            else if (b==k) b=1;
            else b=2;
            convert.push_back(b);
        }
        bool suc = false;
        bool exist = false;
        for(i=0;i<n;i++)
        {
            if(convert[i]==1)
                exist = true;
            if(i>=1 && convert[i] && convert[i-1])
                suc = true;
            if(i>=2 && convert[i] && convert[i-2])
                suc = true;
        }
        if(suc && exist)
            cout<<"yes\n";
        else if(n!=1)
            cout<<"no\n";
        else if(exist)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
}