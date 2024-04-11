#include<bits/stdc++.h>
using namespace std;
int T;
int ans[3];
 
int main()
{
    cin>>T;
    while(T--)
    {
        int i;
        ans[0] = 0, ans[1] = 0, ans[2] = 0;
        string s;
        cin>>s;
        for(i=0;i<s.size();i++)
        {
            if(s.at(i)=='R')
                ans[0]++;
            if(s.at(i)=='P')
                ans[1]++;
            if(s.at(i)=='S')
                ans[2]++;
        }
        int maxi = max(ans[1],ans[2]);
        maxi = max(maxi, ans[0]);
        if(maxi == ans[0])
            for(i=0;i<s.size();i++)
                cout<<"P";
        else if(maxi == ans[1])
            for(i=0;i<s.size();i++)
                cout<<"S";
        else if(maxi == ans[2])
            for(i=0;i<s.size();i++)
                cout<<"R";
        cout<<"\n";
    }
    return 0;
}