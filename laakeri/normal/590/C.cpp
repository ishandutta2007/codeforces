#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

string k[1010];

int u[1010][1010][3];
int d[1010][1010][3];

int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>k[i];
    }
    queue<pair<pair<int, int>, pair<int, int> > > bfs;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            if (k[i][ii]>='1'&&k[i][ii]<='3'){
                bfs.push({{i, ii}, {0, k[i][ii]-'1'}});
            }
        }
    }
    while (!bfs.empty()){
        auto x=bfs.front();
        bfs.pop();
        //cout<<x.F.F<<" "<<x.F.S<<" "<<x.S.S<<endl;
        if (u[x.F.F][x.F.S][x.S.S]) continue;
        u[x.F.F][x.F.S][x.S.S]=1;
        d[x.F.F][x.F.S][x.S.S]=x.S.F;
        for (int i=-1;i<=1;i++){
            for (int ii=-1;ii<=1;ii++){
                if ((i==0)^(ii==0)){
                    int ny=x.F.F+i;
                    int nx=x.F.S+ii;
                    if (ny>=0&&ny<n&&nx>=0&&nx<m){
                        if (k[ny][nx]!='#'){
                            bfs.push({{ny, nx}, {x.S.F+1, x.S.S}});
                        }
                    }
                }
            }
        }
    }
    int f=0;
    int v=1e9;
    int d12=1e8;
    int d13=1e8;
    int d23=1e9;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            if (u[i][ii][0]&&u[i][ii][1]&&u[i][ii][2]){
                f=1;
                //cout<<i<<" "<<ii<<endl;
                //cout<<d[i][ii][0]<<" "<<d[i][ii][1]<<" "<<d[i][ii][2]<<endl;
                v=min(v, d[i][ii][0]+d[i][ii][1]+d[i][ii][2]-2);
                d12=min(d12, d[i][ii][0]+d[i][ii][1]-1);
                d13=min(d13, d[i][ii][0]+d[i][ii][2]-1);
                d23=min(d23, d[i][ii][1]+d[i][ii][2]-1);
            }
        }
    }
    if (!f){
        cout<<-1<<endl;
        return 0;
    }
    v=min(v, d12+d23);
    v=min(v, d12+d13);
    v=min(v, d13+d23);
    cout<<v<<endl;
}