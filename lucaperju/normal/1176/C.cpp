#include <iostream>
#include <vector>
using namespace std;
int ardei[100];
int d[10];
int main()
{
    int t,n,i,j,cnt=0;
    cin>>n;
    ardei[4]=1;
    ardei[8]=2;
    ardei[15]=3;
    ardei[16]=4;
    ardei[23]=5;
    ardei[42]=6;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        a=ardei[a];
        if(a==1 || d[a-1]>d[a])
            ++d[a];
    }
    cout<<n-d[6]*6;
    return 0;
}