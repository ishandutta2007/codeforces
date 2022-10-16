#include<bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<pair<pair<int,int>,int> >pq;
main(){
    int h,q;
    cin>>h>>q;
    int aa=0;
    q++;
    while(q--)
    {
        int i,l,r,a;
        if(q!=0)cin>>i>>l>>r>>a;else i=1,l=1,r=1,a=1;
        int L=l*(1ll<<(h-i)),R=(r+1)*(1ll<<(h-i));
        pq.push({{-L,1},a}),pq.push({{-R,2},a});
        if(a)aa++;
    }
    int aaa=0,bbb=0;
    int ans=0;
    while(!pq.empty())
    {
        pair<pair<int,int>,int>w;
        do{
            w=pq.top();
            pq.pop();
            w.first.first*=-1;
            if(w.first.second==1){
                if(w.second)aaa++;else bbb++;
            }else{
                if(w.second)aaa--;else bbb--;
            }
        }
        while(!pq.empty()&&pq.top().first.first==w.first.first*-1);
        if(aaa==aa&&bbb==0){
            if(ans!=0&&ans!=w.first.first)return puts("Data not sufficient!"),0;
            if(pq.top().first.first*-1!=1+w.first.first)return puts("Data not sufficient!"),0;
            ans=w.first.first;
        }
    }
    if(ans==0)return puts("Game cheated!"),0;
    cout<<ans<<endl;
}