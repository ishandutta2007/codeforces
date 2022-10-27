#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,inf=1e9+7;
int n,w,m,x,v;
long long c[maxn];

int main(){
    scanf("%d%d",&n,&w);
    deque<pair<int,int>> d;
    pair<int,int> cur;
    for(int _=1;_<=n;_++){
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&x);
            while(!d.empty()&&d.front().first<i)d.pop_front();
            while(!d.empty()&&d.back().second<=x)d.pop_back();
            d.push_back({w-m+i,x});
            v=max(i<=w-m?0:-inf,d.front().second);
            c[i]+=v;
            c[i+1]-=v;
        }
        ///jumping
        while(!d.empty()&&d.front().first<m+1)d.pop_front();
        if(d.empty())continue;
        cur=d.front();
        c[m+1]+=max(0,cur.second);
        c[cur.first]-=max(0,cur.second);
        for(int i=cur.first;i<=w;i++){
            while(!d.empty()&&d.front().first<i)d.pop_front();
            v=max(0,d.front().second);
            c[i]+=v;
            c[i+1]-=v;
        }
        while(!d.empty())d.pop_front();
    }
    for(int i=1;i<=w;i++){
        c[i]+=c[i-1];
        printf("%lld ",c[i]);
    }
}
/*
    Good Luck
        -Lucina
*/