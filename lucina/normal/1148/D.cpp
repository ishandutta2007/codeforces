#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int u,v,n;
vector<pair<int,int>> b[2];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&u,&v);
        if(u<v)b[0].push_back(make_pair(v,i));
        else b[1].push_back(make_pair(u,i));//u>v
    }
    if(b[0].size()<b[1].size()){
        printf("%d\n",b[1].size());
        sort(b[1].begin(),b[1].end());
        for(auto i:b[1])
            printf("%d ",i.second);
    }
    else{
        printf("%d\n",b[0].size());
        sort(b[0].begin(),b[0].end());
        reverse(b[0].begin(),b[0].end());
        for(auto i:b[0])
            printf("%d ",i.second);
    }

}
/*#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
struct pa{
    int l,r,pos;
    bool operator<(const pa x)const{
        return l<x.l;
    }
};
int n,u,v;
vector<pa> l1,r1;
vector<vector<int>> candidate[maxn];


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&u,&v);
        if(u<v){
            l1.push_back({u,v,i});
        }
        else r1.push_back({v,u,i});
    }
    sort(l1.begin(),l1.end());
    sort(r1.begin(),r1.end());
    vector<int> best,keep[maxn];
    int l,r,br;
    int pt=0;
    if(!l1.empty()){
        keep[pt].push_back(l1[0].pos);
        l=l1[0].l,r=l1[0].r;
        br=l1[0].r;
        for(auto i:l1){
            if(i.pos==l1[0].pos)continue;
            if(i.l<r){
                keep[pt].push_back(i.pos);
                l=i.l;r=i.r;br=max(br,r);
                continue;
            }
            if(i.l<br){
                vector<int> newv;
                while((l1[keep[pt].back()].r<=i.l)){
                    newv.push_back(keep[pt].back());
                    keep[pt].pop_back();
                }
                newv.push_back(keep[pt].size());
                reverse(newv.begin(),newv.end());
                candidate[pt].push_back(newv);
                r=i.r; br=max(br,r);l=i.l;
                continue;
            }
            else{
                l=i.l;r=i.r;br=max(br,r);
                pt++;
                keep[pt].push_back(i.pos);
            }
        }
    }
    int ma=0;
    for(int i=0;i<=pt;i++){
        ma=max(ma,(int)(keep[i].size()));
        for(auto j:candidate[i]){
            ma=max(ma,j[0]+(int)j.size()-1);
        }
    }
    for(int i=0;i<=pt;i++){
        if(ma==keep[i].size()){
            best=keep[i];
            break;
            }
        bool L=true;
        for(auto j:candidate[i]){
            if(j[0]+j.size()-1==ma){
                best.clear();
                for(int k=0;k<j[0];k++)
                    best.push_back(keep[i][k]);
                for(int k=1;k<j.size();k++)
                    best.push_back(j[k]);
                L=false;
                break;
            }
        }
        if(!L)break;
    }
    for(int i=0;i<=pt;i++){
        candidate[i].clear();
        keep[i].clear();
        }
    l1=r1;
    for(auto i:l1){
        printf("%d %d",i.l,i.r);
    }
        if(!l1.empty()){
        keep[pt].push_back(l1[0].pos);
        l=l1[0].l,r=l1[0].r;
        br=l1[0].r;
        for(auto i:l1){
            if(i.pos==l1[0].pos)continue;
            if(i.l<r){
                keep[pt].push_back(i.pos);
                l=i.l;r=i.r;br=max(br,r);
                continue;
            }
            if(i.l<br){
                vector<int> newv;
                while((l1[keep[pt].back()].r<=i.l)){
                    newv.push_back(keep[pt].back());
                    keep[pt].pop_back();
                }
                newv.push_back(keep[pt].size());
                reverse(newv.begin(),newv.end());
                candidate[pt].push_back(newv);
                r=i.r; br=max(br,r);l=i.l;
                continue;
            }
            else{
                l=i.l;r=i.r;br=max(br,r);
                pt++;
                keep[pt].push_back(i.pos);
            }
        }
    }
     ma=0;
    for(int i=0;i<=pt;i++){
        ma=max(ma,(int)(keep[i].size()));
        for(auto j:candidate[i]){
            ma=max(ma,j[0]+(int)j.size()-1);
        }
    }
    vector<int> best2;
    for(int i=0;i<=pt;i++){
        if(ma==keep[i].size()){
            best2=keep[i];
            break;
            }
        bool L=true;
        for(auto j:candidate[i]){
            if(j[0]+(int)j.size()-1==ma){
                best2.clear();
                for(int k=0;k<j[0];k++)
                    best2.push_back(keep[i][k]);
                for(int k=1;k<j.size();k++)
                    best2.push_back(j[k]);
                L=false;
                break;
            }
        }
        if(!L)break;
    }
    reverse(best2.begin(),best2.end());
    if(best.size()<best2.size())best=best2;
    printf("%d\n",best.size());
    for(auto i:best)
        printf("%d ",i);

}
*/