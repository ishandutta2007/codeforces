#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt0=0,cnt1=0,cnt2=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            if(a%3==0)
                ++cnt0;
            else if (a%3==1)
                ++cnt1;
            else if (a%3==2)
                ++cnt2;
        }
        cout<<cnt0+min(cnt1,cnt2)+(max(cnt1,cnt2)-min(cnt1,cnt2))/3<<'\n';
    }
    return 0;
}