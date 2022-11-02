#include<bits/stdc++.h>
using namespace std;
long long n,l,r,i,t,j;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>l>>r;
        long long sum = 0LL;
        for(i=1;i<=n;i++)
        {
            sum += (n-i)*2;
            if(sum >= l)
                break;
            if(i==n)
                break;
        }
        if(i != n)
        {
            sum -= (n-i)*2;
        }
        i--;
        for(j=l;j<=r;j++)
        {
            if(i==n-1)
                cout<<"1 ";
            else
            {
                long long cur = j-sum;
                if(cur%2LL==1LL)
                    cout<<i+1<<" ";
                else
                    cout<<i+1+(cur)/2<<" ";

                if(cur==2*(n-i-1))
                {
                    sum+=2*(n-i-1);
                    i++;
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}