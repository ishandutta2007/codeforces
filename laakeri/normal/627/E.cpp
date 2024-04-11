#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

set<int> hc;

int k;

int ct[3030];
int tv[3030];

int vv=0;
ll v=0;

int r,c;

int ne[3030];
int ed[3030];

void ins(int x){
    ct[x]++;
    if (ct[x]==1){
        auto ii=hc.insert(x);
        auto it=ii.F;
        if ((int)hc.size()==1){
            ed[x]=0;
            ne[x]=r+1;
            ed[r+1]=x;
        }
        else{
            if (it==hc.begin()){
                ed[x]=0;
            }
            else{
                auto eit=it;
                eit--;
                ed[x]=*eit;
                ne[*eit]=x;
            }
            it++;
            if (it==hc.end()){
                ne[x]=r+1;
                ed[r+1]=x;
            }
            else{
                ne[x]=*it;
                ed[*it]=x;
            }
        }
    }
    int it=x;
    for (int i=0;i<k-1;i++){
        if (ed[it]==0) break;
        it=ed[it];
    }
    int it2=it;

    int h=0;
    int et=0;
    for (;it!=r+1;it=ne[it]){
        while (it2!=r+1&&h<k){
            h+=ct[it2];
            it2=ne[it2];
        }
        if (h<k) break;

        //cout<<(it-ed[it])<<" "<<(r-ed[it2]+1)<<" "<<it2<<" "<<ed[it2]<<endl;

        int ntv=(it-ed[it])*(r-ed[it2]+1);
        vv+=ntv-tv[it];
        tv[it]=ntv;

        h-=ct[it];

        if (et) break;
        if (it==x) et=1;
    }
}

vector<int> h[3030];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>r>>c>>n>>k;
    //r=3000;
    //c=3000;
    //n=3000;
    //k=10;
    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        //x=rand()%3000+1;
        //y=rand()%3000+1;
        h[y].push_back(x);
    }
    for (int i=1;i<=c;i++){
        vv=0;
        for (int ii=0;ii<=r;ii++){
            ct[ii]=0;
            tv[ii]=0;
            ne[ii]=-1;
            ed[ii]=-1;
        }
        hc.clear();
        for (int ii=i;ii<=c;ii++){
            for (int hh:h[ii]){
                ins(hh);
            }
            v+=(ll)vv;
            //cout<<i<<" "<<ii<<" "<<vv<<endl;
        }
    }
    cout<<v<<endl;
}