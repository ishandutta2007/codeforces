#include<bits/stdc++.h>
using namespace std;
int T;

bool checki(int n)
{
    int j;
    bool pass = false;
    for(j=2;j*j<=n;j++)
    {
        if(n%j==0)
            pass = true;
    }
    return !pass;
}

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i,ans;
        cin>>n;
        string s[2] ={"Ashishgup", "FastestFinger"};
        if(n%2==1 && n!=1)
            ans = 0;
        else if (n==1)
            ans = 1;
        else
        {
            int counti=0;
            while(n%2==0)
            {
                n/=2;
                counti++;
            }
            if(n==1 && counti!=1)
                ans = 1;
            else if (n==1 && counti==1)
                ans = 0;
            else if(counti>=2)
            {
                ans = 0;
            }
            else
            {
                if(checki(n))
                    ans = 1;
                else
                    ans =0;
            }
        }
        cout<<s[ans]<<"\n";
    }
    return 0;
}