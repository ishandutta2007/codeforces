#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=15;
const int dx[8]={2,2,-2,-2,1,1,-1,-1},dy[8]={1,-1,1,-1,2,-2,-2,2},ex[8]={0,-1,1,0,1,-1,1,-1},ey[8]={-1,0,0,1,1,1,-1,-1};
int n,arr[mxN][mxN];
pair<int,int> pos[mxN*mxN],wao[mxN][mxN][mxN*mxN][4];
bool inq[mxN][mxN][mxN*mxN][4];
bool eat(int x,int y){return x>0&&y>0&&x<=n&&y<=n;}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            pos[arr[i][j]]={i,j};
        }
    }
    for(int i=0;i<mxN;i++){
        for(int j=0;j<mxN;j++){
            for(int k=0;k<mxN*mxN;k++){
                for(int l=0;l<4;l++)wao[i][j][k][l]={1e18,0};
            }
        }
    }
    queue<pair<pair<int,int>,pair<int,int> > > bfs;
    for(int i=1;i<4;i++){
        wao[pos[1].ff][pos[1].ss][1][i]={0,0};
        inq[pos[1].ff][pos[1].ss][1][i]=1;
        bfs.push({pos[1],{1,i}});
    }
    while(bfs.size()){
        auto x=bfs.front();
        bfs.pop();
        inq[x.ff.ff][x.ff.ss][x.ss.ff][x.ss.ss]=0;
        for(int i=0;i<8;i++){
            int wa=x.ff.ff+dx[i],wb=x.ff.ss+dy[i];
            if(eat(wa,wb)){
                auto e=wao[x.ff.ff][x.ff.ss][x.ss.ff][x.ss.ss];
                if(x.ss.ss!=1){
                    e.ff++;
                    e.ss++;
                }
                e.ff++;
                int z=x.ss.ff;
                if(arr[wa][wb]==z+1)z++;
                if(wao[wa][wb][z][1]>e){
                    wao[wa][wb][z][1]=e;
                    if(!inq[wa][wb][z][1]){
                        inq[wa][wb][z][1]=1;
                        bfs.push({{wa,wb},{z,1}});
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<8;j++){
                int wa=x.ff.ff+ex[j]*i,wb=x.ff.ss+ey[j]*i;
                if(eat(wa,wb)){
                    auto e=wao[x.ff.ff][x.ff.ss][x.ss.ff][x.ss.ss];
                    int z=2+(j<4);
                    if(x.ss.ss!=z){
                        e.ff++;
                        e.ss++;
                    }
                    e.ff++;
                    int zz=x.ss.ff;
                    if(arr[wa][wb]==zz+1)zz++;
                    if(wao[wa][wb][zz][z]>e){
                        wao[wa][wb][zz][z]=e;
                        if(!inq[wa][wb][zz][z]){
                            inq[wa][wb][zz][z]=1;
                            bfs.push({{wa,wb},{zz,z}});
                        }
                    }
                }
            }
        }
    }
    pair<int,int> ans={1e18,0};
    for(int i=1;i<4;i++){
        ans=min(ans,wao[pos[n*n].ff][pos[n*n].ss][n*n][i]);
        //cout<<wao[pos[n*n].ff][pos[n*n].ss][n*n][i].ff<<" "<<wao[pos[n*n].ff][pos[n*n].ss][n*n][i].ss<<"\n";
    }
    cout<<ans.ff<<" "<<ans.ss<<"\n";
}