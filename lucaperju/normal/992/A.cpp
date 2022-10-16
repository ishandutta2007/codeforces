#include <iostream>

using namespace std;
int fv[300005];
int main()
{
    int mx=0,mn=0,n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        if(fv[a+100005]==0 && a!=0)
            ++cnt;
        fv[a+100005]++;
    }
    cout<<cnt;
    return 0;
}