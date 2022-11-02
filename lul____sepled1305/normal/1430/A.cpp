#include<bits/stdc++.h>
using namespace std;
int T;
 
int main()
{
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n== 1 ||n==2 || n==4)
            cout<<"-1\n";
        else if(n==7)
            cout<<"0 0 1\n";
        else
        {
            int i;
            for(i=0;i<5;i++)
            {
                int cur = n-3*i;
                if(cur%5 == 0)
                {
                    cout<<i<<' '<<cur/5<<' '<<0<<endl;
                    break;
                }
            }
        }
    }
}