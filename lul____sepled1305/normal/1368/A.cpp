#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        long long a,b,n,ans = 0,ori_a,ori_b, ans2 = 1;
        cin>>a>>b>>n;
        ori_a = a; ori_b=b;
        if(a>b) swap(a,b);
        while(b<=n)
        {
            a+=b;
            swap(a,b);
            ans++;
        }
        a = ori_a; b = ori_b;
        if(a>b) swap(a,b);
        b+=a;
        while(b<=n)
        {
            a+=b;
            swap(a,b);
            ans2++;
        }
        cout<<min(ans,ans2)<<"\n";
    }
    return 0;
}