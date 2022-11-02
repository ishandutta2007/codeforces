#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,pointer1,pointer2,Alice=0,Bob=0,last,cur=0,turn =1,i;
        cin>>n;
        pointer1 = 0; pointer2 = n-1;
        int candy[n];
        for(i=0;i<n;i++)
        {
            cin>>candy[i];
        }
        last = 0;
        while(pointer1<=pointer2)
        {
            cur =0;
            if(turn%2==1)
            {
                while(cur<=last && pointer1<=pointer2)
                {
                    cur+=candy[pointer1];
                    pointer1++;
                }
                Alice+=cur;
                last = cur;
                turn++;
            }
            else
            {
                while(cur<=last && pointer1<=pointer2)
                {
                    cur+=candy[pointer2];
                    pointer2--;
                }
                Bob+=cur;
                last = cur;
                turn++;
            }
        }
        cout<<turn-1<<" "<<Alice<<" "<<Bob<<"\n";
    }
}