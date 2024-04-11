#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,i;
    cin>>n>>k;
    string s;
    cin>>s;
    int gr[26];
    for(i=0;i<26;i++)
    {
        gr[i] = 0;
    }
    for(i=0;i<n;i++)
    {
        gr[s.at(i)-'a']++;
    }
    int ans=0, counti=0; int prev = -5;
    for(i=0;i<26;i++)
    {
        if(gr[i]>0 && i-prev >=2)
        {
            counti++;
            prev = i;
        }
    }
    if(counti<k)
        cout<<-1;
    else
    {
        prev = -5; counti = 0;
        for(i=0;i<26;i++)
        {
            if(gr[i]>0 && i-prev  >=2 && counti<k)
            {
                ans+=i+1;
                prev = i;
                counti++;
            }
        }
        cout<<ans;
    }
    return 0;
}