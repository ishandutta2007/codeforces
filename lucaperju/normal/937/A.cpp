#include <iostream>

using namespace std;
int fv[605];
int main()
{
    int n,i,j,cnt=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        fv[a]++;
    }
    for(i=1;i<=600;++i)
    {
        if(fv[i])
            ++cnt;
    }
    cout<<cnt;
    return 0;
}