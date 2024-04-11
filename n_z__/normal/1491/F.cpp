#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int id=2;
        auto que=[&](int l,int r,int id){
            cout<<"? 1 "<<r-l+1<<endl;
            cout<<id<<endl;
            for(int x=l;x<=r;x++)
            cout<<x<<' ';cout<<endl;
            int qwq;
            cin>>qwq;
            return qwq!=0;
        };
        while(!que(1,id-1,id))id++;
        int l=1,r=id-1,res=0;
        while(l<=r)
        {
            int mi=(l+r)/2;
            if(que(mi,id-1,id))l=mi+1,res=mi;
            else r=mi-1;
        }
        vector<int>ans;
        for(int x=id+1;x<=n;x++)
        if(!que(x,x,id))ans.push_back(x);
        for(int x=1;x<id;x++)
        if(x!=res)ans.push_back(x);
        cout<<"! "<<ans.size()<<' ';
        for(auto q:ans)cout<<q<<' ';cout<<endl;
    }
}