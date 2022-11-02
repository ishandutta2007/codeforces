#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int length,i,a,b,ans=0;;
        length = s.size();
        set<pair<pair<int,int>,int>> po;
        a=0, b=0;
        for(i=0;i<length;i++)
        {
            int path;
            int aprev =a, bprev =b;
            bool cur=false;
            if(s.at(i)=='N')
            {
                a++;
                path=1;
            }
            if(s.at(i)=='S')
            {
                a--;
                path = 4;
            }
            if(s.at(i)=='W')
            {
                b--;
                path =3;
            }
            if(s.at(i)=='E')
            {
                b++;
                path =2;
            }
            if(po.count({{a,b},path}))
                cur = true;
            po.insert({{a,b},path});
            po.insert({{aprev,bprev},5-path});
            if(cur)
                ans++;
            else
                ans+=5;
        }
        cout<<ans<<"\n";

    }
    return 0;
}