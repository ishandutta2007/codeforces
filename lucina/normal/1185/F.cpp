#include<bits/stdc++.h>
using namespace std;
const int mask=512;
int n,m,cost,a[mask],ncost[mask],lcost,ma,best;
pair<int,int> nid[mask];
vector<pair<int,int>> v[mask];
signed main(){
    for(int i=0;i<mask;i++)
        nid[i]=make_pair(0,0);
    scanf("%d%d",&n,&m);
    int tt,rr,msk=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&tt);
        msk=0;
        while(tt--){
            scanf("%d",&rr);
            msk|=(1<<(rr-1));
        }
        a[msk]++;
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&cost);
        scanf("%d",&tt);
        msk=0;
        while(tt--){
            scanf("%d",&rr);
            msk|=(1<<(rr-1));
        }
       v[msk].push_back(make_pair(cost,i));
       if(v[msk].size()>=3){
        sort(v[msk].begin(),v[msk].end());v[msk].pop_back();
       }
    }
    for(int i=0;i<mask;i++)
        if((int)v[i].size()==2)
        sort(v[i].begin(),v[i].end());
    for(int i=0;i<mask;i++){
        if(v[i].empty())continue;
        for(int j=0;j<mask;j++){
            if(v[j].empty())continue;
            if(j==i){
                if(v[i].size()>1){
                cost=v[i][0].first+v[i][1].first;
                if(ncost[i]==0||cost<ncost[i]){
                    ncost[i]=cost;
                    nid[i].first=v[i][0].second;
                    nid[i].second=v[i][1].second;
                    }
                }
                continue;
            }
            cost=v[j][0].first+v[i][0].first;
            msk=(i|j);
            if(ncost[msk]==0||cost<ncost[msk]){
                ncost[msk]=cost;
                nid[msk].first=v[i][0].second;
                nid[msk].second=v[j][0].second;
            }
        }
    }
    int ct=0;
    lcost=(2e9+7);
    for(int j=0;j<mask;j++){
        if(ncost[j]==0)continue;
        ct=0;
        for(int i=0;i<mask;i++){
            ct+=((j&i)==i?a[i]:0);
        }
        if(ct>ma){
            ma=ct;
            best=j;
            lcost=ncost[j];
        }
        else if(ct==ma){
            if(ncost[j]<lcost){
                best=j;lcost=ncost[j];
            }
        }
    }
    printf("%d %d\n",nid[best].first,nid[best].second);
}
/*
    Good Luck
         -Lucina
*/