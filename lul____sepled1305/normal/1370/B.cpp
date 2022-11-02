#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i,j,odd= 0,even=0;
        int cased = 0;
        cin>>n;
        int a[2*n];
        bool us[2*n];
        for(i=0;i<2*n;i++)
        {
            cin>>a[i];
            us[i] = true;
            if(a[i]%2)
                odd++;
            else
                even++;
        }
        if(odd%2==1)
            cased = 1;
        else if(odd>0)
            cased = 2;
        else
            cased = 3;

        if(cased == 1)
        {
            bool od = false, ev = false;
            for(i=0;i<2*n;i++)
            {
                if(od && ev)
                    break;
                if(a[i]%2==1 && od==false)
                {
                    od = true;
                    us[i] = false;
                }
                if(a[i]%2==0 && ev==false)
                {
                    ev = true;
                    us[i] = false;
                }
            }
        }
        if(cased == 2)
        {
            bool od = false, ev = false;
            for(i=0;i<2*n;i++)
            {
                if(od && ev)
                    break;
                if(a[i]%2 && od==false)
                {
                    od = true;
                    us[i] = false;
                }
                else if(a[i]%2 && ev==false)
                {
                    ev = true;
                    us[i] = false;
                }
            }
        }
        if(cased == 3)
        {
            bool od = false, ev = false;
            for(i=0;i<2*n;i++)
            {
                if(od && ev)
                    break;
                if(a[i]%2==0 && od==false)
                {
                    od = true;
                    us[i] = false;
                }
                else if(a[i]%2==0 && ev==false)
                {
                    ev = true;
                    us[i] = false;
                }
            }
        }
        cout<<"\n";
        int prin = 0;
        while(prin<n-1)
        {
            bool first = true;
            int od =1;
            for(i=0;i<2*n;i++)
            {
                if(us[i] && first)
                {
                    us[i] = false;
                    first = false;
                    cout<<i+1<<" ";
                    if(a[i]%2==0)
                        od = 0;
                }
                else if(!first && us[i])
                {
                    if(a[i]%2==od)
                    {
                        us[i] = false;
                        cout<<i+1<<" ";
                        break;
                    }
                }
            }
            prin++;
            cout<<"\n";
        }
    }
    return 0;
}