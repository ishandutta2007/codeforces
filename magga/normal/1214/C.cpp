#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,d,e;cin>>n;
    string s;cin>>s;
    if(n%2==1)
    {
        cout<<"No"<<endl;
    }
    else
    {
        long long int rec=0;
        bool b=false;
        bool c = false;
        for(long long int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                rec++;
            }
            else
            {
                rec--;
            }
            if(rec<0 && !b)
            {
                b=true;
                rec++;
            }
             if(b && rec<0)
            {
                c=true;
                break;
            }
        }
        if(c || (b && rec!=1) || (rec!=0 && !b))
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve(); 
}