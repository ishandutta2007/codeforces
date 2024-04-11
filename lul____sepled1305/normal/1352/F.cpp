#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int a,b,c,i;
        cin>>a>>b>>c;
        if(a>0 && c>0)
        {
            for(i=0;i<a+1;i++)
                cout<<"0";
            for(i=0;i<c+1;i++)
                cout<<"1";
            for(i=0;i<b-1;i++)
            {
                if(i%2==0)
                    cout<<"0";
                else
                    cout<<"1";
            }
        }
        else if(b>0 && c>0)
        {
            for(i=0;i<c+1;i++)
                cout<<"1";
            for(i=0;i<b;i++)
            {
                if(i%2==0)
                    cout<<"0";
                else
                    cout<<"1";
            }
        }
        else if(a>0 && b>0)
        {
            for(i=0;i<a+1;i++)
                cout<<"0";
            for(i=0;i<b;i++)
            {
                if(i%2==0)
                    cout<<"1";
                else
                    cout<<"0";
            }
        }
        else if (a>0)
        {
            for(i=0;i<a+1;i++)
                cout<<"0";
        }
        else if (c>0)
        {
            for(i=0;i<c+1;i++)
                cout<<"1";
        }
        else
        {
            for(i=0;i<b+1;i++)
            {
                if(i%2==0)
                    cout<<"0";
                else
                    cout<<"1";
            }
        }
        cout<<"\n";
    }
}