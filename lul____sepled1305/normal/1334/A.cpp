#include<bits/stdc++.h>
using namespace std;
int i,j,k,play,ye,n,t,diff,old_ye,old_no;
bool yes=true;

int main()
{
    cin>>t;
    for(i=0;i<t;i++)
    {
        yes=true;
        diff=-1e9;
        old_ye=-1; old_no=-1;
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>play;
            cin>>ye;
            if(diff > play-ye || play < ye || play<old_ye || ye<old_no)
            {
                yes=false;
            }
            else
            {
                diff = play-ye;
                old_ye=play;
                old_no=ye;
            }
        }
        if(yes)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}