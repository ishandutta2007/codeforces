#include<bits/stdc++.h>
using namespace std;
int n,k,l,o,p,boom,i,maxi;
int a[300010];
int b[300010];
stack<int> whoa;
stack<int> whoa2;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]>maxi)
        {
            maxi=a[i];
        }
    }
    for(i=1;i<=n;i++)
    {
        //cout<<a[i];
        if(!whoa.empty())
        {
                   if(a[i]< whoa.top() && !whoa.empty())
        {
            whoa.push(a[i]);
            //cout<<"I'm a big bug";
        }
        else if(a[i]==whoa.top() && !whoa.empty())
        {
            whoa.pop();
            //cout<<whoa.size();
            //cout<<"I'm a big bug";
        }
                else if(a[i]!=maxi)
        {
            boom++;
            //cout<<"I'm a big bug";
            break;
        }
        else if(a[i]==maxi && !whoa.empty())
        {
            boom++;
            break;
        }

        }
        else if(whoa.empty()&&a[i]!=maxi)
        {
            whoa.push(a[i]);
            //cout<<"I'm a big bug";
        }
    }
    if(boom==1)
    {
        cout<<"NO";
    }
    else if(whoa.empty())
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}