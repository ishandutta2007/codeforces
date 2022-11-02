#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,k,ans;
        cin>>n>>k;
        if(n<k)
        {
            cout<<"NO\n";
        }
        else if(n%2==1 && k%2==0)
        {
            cout<<"NO\n";
        }
        else
        {
            if(n%2==0)
            {
                if(k%2==1)
                {
                    if(n<2*k)
                        cout<<"NO\n";
                    else
                    {
                        cout<<"YES\n";
                        while(k--)
                        {
                            if(k!=0)
                            {
                                cout<<"2 ";
                                n-=2;
                                continue;
                            }
                            else
                            {
                                cout<<n<<"\n";
                            }
                        }
                    }
                }
                else
                {
                    cout<<"YES\n";
                    while(k--)
                    {
                        if(k!=0)
                        {
                            cout<<"1 ";
                            n--;
                            continue;
                        }
                        else
                            cout<<n<<"\n";
                    }
                }
            }
            else
            {
                cout<<"YES\n";
                    while(k--)
                    {
                        if(k!=0)
                        {
                            cout<<"1 ";
                            n--;
                            continue;
                        }
                        else
                            cout<<n<<"\n";
                    }
            }
        }
    }
}