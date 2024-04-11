#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i,counti = 0;
        bool pa = true;
        vector<int> gg;
        string s;
        cin>>s;
        s.push_back(0);
        n = s.size();
        for(i=0;i<n;i++)
        {
            if(pa && s.at(i)=='1')
                counti++;
            else if(pa)
            {
                gg.push_back(counti);
                pa = false;
            }
            else if(s.at(i)=='1')
            {
                counti = 1;
                pa = true;
            }
        }
        sort(gg.begin(),gg.end(),greater<int>());
        int siz = gg.size();
        int ans = 0;
        for(i=0;i<siz;i++)
        {
            if(i%2==0)
                ans+=gg[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}