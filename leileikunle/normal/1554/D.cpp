#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

void solve()
{
    int n; cin>>n;
    if(n<27){
        for(int i=1;i<=n;i++) cout<<(char)('a'+i-1);
        cout<<endl;
    }else{
        int t = (n-1)/4,res = n-(t*4+1);
        if((n-1)%4==0)
        {
            t--;
            res+=4;
        }
        for(int i=1;i<=t*2+1;i++) cout<<'a';
        for(int i=1;i<=res;i++) cout<<(char)('a'+i);
        for(int i=1;i<=t*2;i++) cout<<"a";
        cout<<endl;
    }
}
signed main()
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    //-------------------

    int tt=1;
    cin>>tt;
    while(tt--)
    {
        solve();
    }
    return 0;
    //-------------------
end:
    cerr<<"Time used:"<<clock() - c1<<"ms"<<endl;
    return 0;
}