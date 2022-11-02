#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i;
        bool issort = true, isfix = false;
        cin>>n;
        int a[n];
        bool fix[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==i+1)
                fix[i]=true;
            else
                issort = false,fix[i]=false;
        }
        int counti = 0;
        bool nope = false;
        for(i=0;i<n;i++)
        {
            if(!nope && !fix[i])
            {
                nope = true;
                counti++;
            }
            else if(fix[i] && nope)
            {
                nope = false;
            }
        }
        cout<<min(counti,2)<<"\n";
    }
}