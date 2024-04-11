#include<bits/stdc++.h>
using namespace std;

string solve()
{
    string inp;
    cin>>inp;

    int type[3]={0,0,0};

    for(type[0]=0;type[0]<2;type[0]++)
        for(type[1]=0;type[1]<2;type[1]++)
            for(type[2]=0;type[2]<2;type[2]++)
            {
                int diff=0;

                for(auto w:inp)
                {
                    diff+=2*type[w-'A']-1;

                    if(diff<0)break;
                }
                if(diff==0)return "YES";
            }
    return "NO";
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<"\n";
    }

    return 0;
}