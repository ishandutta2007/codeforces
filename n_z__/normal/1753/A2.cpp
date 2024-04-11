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
        vector<int>a(n+1);
        int sum=0;
        for(int x=1;x<=n;x++)
        cin>>a[x],sum+=a[x];
        if(abs(sum)%2==1)cout<<-1<<endl;
        else {
            int lst=0,lstid=0;
            vector<pair<int,int>>ans;
            for(int x=1;x<=n;x++)
            {
                if(lst!=0&&a[x]==0)continue;
                else if(lst==0&&a[x]==0)ans.push_back({x,x});
                else if(lst==0)lst=a[x],lstid=x;
                else if(lst!=a[x]){
                    ans.push_back({lstid,lstid});
                    if(lstid+1<=x-1)ans.push_back({lstid+1,x-1});
                    ans.push_back({x,x});
                    lst=0;
                }
                else {
                    if(lstid==x-1)ans.push_back({lstid,x});
                    else {
                        ans.push_back({lstid,lstid});
                        if(lstid+1<=x-2)ans.push_back({lstid+1,x-2});
                        ans.push_back({x-1,x});
                    }
                    lst=0;
                }
            }
            cout<<ans.size()<<endl;
            for(auto q:ans)
            cout<<q.first<<' '<<q.second<<endl;
        }
    }
}