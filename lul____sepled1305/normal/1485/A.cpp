
#include<bits/stdc++.h>
using namespace std;
 
void solve()
{
    int a,b, ans = 1e9;
    cin>>a>>b;
    for(int i=0;i<100;i++)
    {
        if(b == 1)
        {
            b++;
            continue;
        }
        int A = a, counti = 0;
        while(A != 0)
            A/=b, counti++;
        b++;
        ans = min(ans,i+counti);
    }
    cout<<ans<<endl;
    
}
 
int main()
{
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}