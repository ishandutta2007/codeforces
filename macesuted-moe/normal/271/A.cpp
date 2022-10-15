#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(true)
    {
        n++;
        int a,b,c,d;
        a=n%10;
        b=n/10%10;
        c=n/100%10;
        d=n/1000%10;
        if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
        {
            cout<<n<<endl;
            return 0;
        }
    }
    return 0;
}