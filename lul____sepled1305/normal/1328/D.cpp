
#include<bits/stdc++.h>
using namespace std;
int T;
 
int main()
{
    cin>>T;
    while(T--)
    {
        int ans=1,n,i;
        cin>>n;
        int t[n];
        for(i=0;i<n;i++)
        {
            cin>>t[i];
            if(i>0 && t[i]!=t[i-1])
                ans = 2;
        }
        if(ans==1)
        {
            cout<<"1\n";
            for(i=0;i<n;i++)
                cout<<"1 ";
            cout<<"\n";
        }
        else
        {
            bool pass = false;
            for(i=0;i<n;i++)
            {
                if(t[i]==t[(i+1)%n])
                    pass = true;
            }
            if(n%2==0)
            {
                cout<<"2\n";
                for(i=0;i<n;i++)
                    cout<<i%2+1<<" ";
                cout<<"\n";
            }
            else if(pass)
            {
                cout<<"2\n";
                bool first  = true;
                int prin = 1;
                int color[n];
                color[n-1] = 1;
                for(i=0;i<n;i++)
                {
                    if(t[i]==t[((i-1)+n)%n]&&first)
                        first=false, color[i]=color[(i-1+n)%n];
                    else
                        color[i] = color[(i-1+n)%n]^1;
                }
                for(i=0;i<n;i++)
                    cout<<color[i]+1<<" ";
                cout<<"\n";
            }
            else
            {
                cout<<"3\n";
                for(i=0;i<n-1;i++)
                    cout<<i%2+1<<" ";
                cout<<"3\n";
            }
        }
    }
}