#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t,i,j,cnt=0,k,mn=2;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(b%3)
        {
            if(a%3==0)
                cout<<"Bob\n";
            else
                cout<<"Alice\n";
        }
        else
        {
            ++a;
            int mgr=b/3;
            mgr=(mgr-1)*3+4;
            int nrg=a/mgr;
            a-=nrg*mgr;
            if(a%3==1)
                cout<<"Bob\n";
            else
                cout<<"Alice\n";
        }
    }
    return 0;
}