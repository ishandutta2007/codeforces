#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,k,x,y,z;
const long long INF=1e17;
long long dist[810][810];
long long node[810][810];
bool ch[810];


struct st{
    long long val;
    int u,v;
    st():
        val(0LL),u(0),v(0){}
    st(long long _val,int _u,int _v):
        val(_val),u(_u),v(_v){}
    bool operator<(const st &z)const{
    return val<z.val;
    }
   /* friend bool cmp(const st &a,const st &b){
        return a.u==b.u||a.u==b.v||a.v==b.u||a.v==b.v;
    }*/
};
vector<st> b;
vector<int> t;
vector<pair<int,long long>> a[805];
void floyd_worshall(int v,bool sorry_floyd){
    for(int i=1;i<=v;i++){
    for(int j=1;j<=v;j++)
        dist[i][j]=INF,node[i][j]=INF;
        node[i][i]=0;
        dist[i][i]=0;
        }
    if(!sorry_floyd){
    while(m--){
        scanf("%d%d%d",&x,&y,&z);
        node[x][y]=z;
        node[y][x]=z;
    }
    }
    else{
        for(auto i:b){
        int id1=lower_bound(t.begin(),t.end(),i.u)-t.begin();
        int id2=lower_bound(t.begin(),t.end(),i.v)-t.begin();;
        node[id1][id2]=i.val;
        node[id2][id1]=i.val;
    }
    }
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            ch[j]=false;
        }
        for(int j=1;j<=v;j++){
            long long mi=INF;
            for(int k=1;k<=v;k++){
                if(!ch[k]&&dist[i][k]<mi){
                    mi=dist[i][k];
                    x=k;
                }
            }
            ch[x]=true;
            for(int k=1;k<=v;k++){
                dist[i][k]=min(dist[i][k],node[x][k]+mi);
            }
        }
    }
    vector<long long> all;
    for(int i=1;i<=v;i++)
    for(int j=1;j<=i;j++){
        if(dist[i][j]>0&&dist[i][j]!=INF){
            all.push_back(dist[i][j]);
        }
    }
    sort(all.begin(),all.end());
    printf("%lld\n",all[k-1]);
    exit(0);
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    if(n<=400){
        floyd_worshall(n,false);
    }
    while(m--){
        scanf("%d%d%d",&x,&y,&z);
        b.push_back(st((long long)z,x,y));
    }
    t.push_back(-1);
    sort(b.begin(),b.end());
    while((int)b.size()>k)b.pop_back();
    for(auto i:b){
        t.push_back(i.u);
        t.push_back(i.v);
    }
    sort(t.begin(),t.end());
    t.erase(unique(t.begin(),t.end()),t.end());
    floyd_worshall((int)t.size(),true);

}
/*
    Good Luck
        -Lucina
*/