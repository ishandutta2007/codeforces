#include<bits/stdc++.h>
using namespace std;
int main()
{
    int b,g,n;

    cin>>b>>g>>n;

    int ret=0;

    for(int i=0;i<=n;i++)
    {
        int b_=b-i;
        int g_=g-(n-i);

        if(b_>=0&&g_>=0)ret++;
    }

    printf("%i\n",ret);
    return 0;
}