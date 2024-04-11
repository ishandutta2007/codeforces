#include<bits/stdc++.h>
using namespace std;
int n,k,l,o,p,boom,i,maxi,h,f;
int a[300010];
int b[300010];
stack<int> wow;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>l;
        a[i]=l%2;
    }
    h=1;
    a[n+1]=19283;
    for(i=1;i<=n;i++)
    {
        if(a[i+1]-a[i]!=0)
        {
            b[h]=i-f;
            f=i;
            h++;
        }
    }
    maxi=h;
    for(i=1;i<h;i++)
    {
        if(!wow.empty()){
        if(b[i]%2==1 && (i-wow.top())%2==1)
        {
            wow.push(i);
        }
        else if(b[i]%2==1 && (i-wow.top())%2==0)
        {
            wow.pop();
        }
        }
        else
        {
            if(b[i]%2==1)
            {
                wow.push(i);
            }
        }
    }
    if(wow.size()==1)
    {
        wow.top();
        int sum=0;
        for(i=1;i<h;i++)
        {
            if(i!=wow.top() && b[i]%2==1)
            {
                sum++;
            }
            if(i==wow.top())
            {
                if(sum%2==1)
                {
                    cout<<"NO";
                    p=1;
                    break;
                }
                else
                {
                    sum=0;
                }
            }

        }
        if(sum%2==1 && p==0)
        {
            cout<<"NO";
        }
        else
        {
            cout<<"YES";
        }
    }
    else if(wow.empty())
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}