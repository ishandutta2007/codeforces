#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long n;
        cin>>n;
        if(n%2050 != 0) {cout<<"-1\n"; continue;}
        else
        {
            n = n/2050;
            int ans = 0;
            while(n!=0)
            {
                ans += n%10;
                n = n/10;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}