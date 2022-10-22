#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int t;
int n;
char c[maxn][maxn][maxn];
int p[maxn];
vector<int> ch[maxn];
inline bool query(int x,int y,int z) {
    if(x>y) return c[y][x-y][z-1]=='1';
    else return c[x][y-x][z-1]=='1';
}
void rec_tree(int u,int v) {
    for(int w=1;w<=n;w++) {
        if(p[w]==-1 && query(v,w,u)) {
            p[w]=u;
            rec_tree(w,u);
        }
    }
}

int d[maxn][maxn];

int q[maxn];

bool check_tree() {
    for(int u=1;u<=n;u++) {
        for(int v=1;v<=n;v++) {
            d[u][v]=1e9;
        }
        d[u][u]=0;
        int sz=0;
        q[sz]=u;
        sz++;
        int ind=0;
        while(ind<sz) {
            int v=q[ind];
            ind++;
            for(auto w:ch[v]) {
                if(d[u][w]>d[u][v]+1) {
                    d[u][w]=d[u][v]+1;
                    q[sz++]=w;
                }
            }
        }

        for(int v=1;v<=n;v++) {
            for(int w=1;w<v;w++) {
                if(query(w,v,u) != (d[u][v]==d[u][w]) ) return false;
            }
        }
    }
    return true;
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n-1;i++) {
            for(int j=1;j<=n-i;j++) {
                scanf("%s",c[i][j]);
            }
        }

        bool ok=false;

        for(int j=2;j<=n;j++) {
            for(int k=2;k<=n;k++) p[k]=-1;
            p[j]=1;
            rec_tree(1,j);
            rec_tree(j,1);

            bool gd=true;
            for(int k=1;k<=n;k++) {
                if(p[k]==-1) {
                    gd=false;
                    break;
                }
                ch[k].clear();
            }

            if(!gd) continue;

            for(int k=2;k<=n;k++) {
                ch[p[k]].push_back(k);
                ch[k].push_back(p[k]);
            }

            if(check_tree()) {
                ok=true;
                printf("Yes\n");
                for(int i=2;i<=n;i++) {
                    printf("%d %d\n",i,p[i]);
                }
                break;
            }

        }

        if(!ok) {
            printf("No\n");
        }

    }
    return 0;
}