#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;
char v[500];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie();
    long long ci,cc,i,j,s=0,cnt=0,cnt0=0,n,a,k,ok=0;
    cin>>v;
    n=strlen(v);
    cin>>k;
    for(i=0;i<n;++i)
    {
        if(v[i]!='*' && v[i]!='?')
            ++cnt;
        else
        if(v[i]=='*')
            ++ok;
        else
            ++cnt0;
    }
    if(cnt<k)
    {
        if(!ok)
        {
            cout<<"Impossible";
            return 0;
        }
        for(i=0;i<n;++i)
        {
            if(v[i]!='*' && v[i]!='?')
                cout<<v[i];
            else
            if(v[i]=='*')
                while(cnt<k)
                {
                    cout<<v[i-1];
                    --k;
                }
        }
    }
    else
    if(cnt==k)
    {
        for(i=0;i<n;++i)
            if(v[i]!='*' && v[i]!='?')
                cout<<v[i];
    }
    else
    {
        if(cnt-ok-cnt0>k)
        {
            cout<<"Impossible";
            return 0;
        }
        for(i=0;i<n;++i)
        {
            if((v[i+1]=='?' || v[i+1]=='*') && cnt>k)
                --cnt;
            else if(v[i]!='*' && v[i]!='?')
                cout<<v[i];
        }
    }
}