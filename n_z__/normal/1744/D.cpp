#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a;
        int cnt=0;
        for(int x=1;x<=n;x++)
        {
            int y;
            cin>>y;
            cnt+=__builtin_ctzll(y);
            a.push_back(__builtin_ctzll(x));
        }
        sort(a.begin(),a.end(),[&](auto a,auto b){return a>b;});
        int now=0;
        while(cnt<n&&now<a.size())cnt+=a[now],now++;
        if(cnt>=n)cout<<now<<endl;
        else cout<<-1<<endl;
    }
}