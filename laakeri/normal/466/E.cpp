#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100001];

int q[100001][4];

int tlol=1;

int l[100001];
int r[100001];

int dd[100001];

int used[100001];

void dfs(int x, int d){
    if (used[x]) return;
    used[x]=1;
    tlol++;
    dd[x]=d;
    l[x]=tlol;
    for (int nx:g[x]){
        dfs(nx, d+1);
    }
    r[x]=tlol;
    tlol++;
}

int u[100001];
int us[100001];

int getu(int a){
    if (u[a]!=a){
        return getu(u[a]);
    }
    return a;
}

void un(int a, int b){
    int ua=getu(a);
    int ub=getu(b);
    if (ua!=ub){
        if (us[ua]<us[ub]){
            us[ub]+=us[ua];
            u[ua]=ub;
        }
        else{
            us[ua]+=us[ub];
            u[ub]=ua;
        }
    }
}

int pe[100001];

int hb[100001];

int vv[100001];

vector<pair<int,int> > qq[100001];

int main(){
    int n,m;
    cin>>n>>m;
    int q3s=0;
    for (int i=0;i<m;i++){
        int qt;
        cin>>qt;
        if (qt==1){
            int x,y;
            cin>>x>>y;
            g[y].push_back(x);
            hb[x]=1;
            q[i][0]=1;
            q[i][1]=x;
            q[i][2]=y;
        }
        if (qt==2){
            int a;
            cin>>a;
            q[i][0]=2;
            q[i][1]=a;
        }
        if (qt==3){
            int a,b;
            cin>>a>>b;
            q[i][0]=3;
            q[i][1]=a;
            q[i][2]=b;
            q3s++;
            qq[b].push_back(make_pair(a, q3s));
        }
    }
    for (int i=1;i<=n;i++){
        u[i]=i;
        us[i]=1;
    }
    for (int i=1;i<=n;i++){
        if (!hb[i]){
            dfs(i, 1);
        }
    }
    for (int i=1;i<=n;i++){
        dfs(i, 1);
    }
    int ps=0;
    for (int i=0;i<m;i++){
        if (q[i][0]==1){
            un(q[i][1], q[i][2]);
        }
        if (q[i][0]==2){
            ps++;
            for (auto qqq:qq[ps]){
                int x=qqq.first;
                int y=q[i][1];
                if (y==x){
                    vv[qqq.second]=2;
                }
                else{
                    if (getu(y)==getu(x)){
                        if (dd[x]<=dd[y]){
                            if (l[y]>=l[x]&&l[y]<=r[x]){
                                vv[qqq.second]=2;
                            }
                            else{
                                vv[qqq.second]=1;
                            }
                        }
                        else{
                            vv[qqq.second]=1;
                        }
                    }
                    else{
                        vv[qqq.second]=1;
                    }
                }
            }
        }
    }
    for (int i=1;i;i++){
        if (vv[i]==0) break;
        if (vv[i]==2) cout<<"YES"<<'\n';
        if (vv[i]==1) cout<<"NO"<<'\n';
    }
}