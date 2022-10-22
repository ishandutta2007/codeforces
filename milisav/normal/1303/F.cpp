#include<bits/stdc++.h>
using namespace std;
struct trm {
    int i;
    short x,y;
};
int n,m,q;
int x,y,c;
int a[400][400];
vector<trm> *add;
vector<trm> *rem;
vector<pair<short,short> > *ost;
int ans[3000000];
int val[400][400];
vector<pair<short,short> > comps[100000];
int cc;
void unite(int a,int b,int i) {
    if(a==b) return;
    if(i>0) ans[i]--;
    else ans[-i]++;
    if(comps[a].size()>comps[b].size()) {
        for(auto g:comps[b]) {
            comps[a].push_back(g);
            val[g.first][g.second]=a;
        }
        comps[b].clear();
    }
    else {
        for(auto g:comps[a]) {
            comps[b].push_back(g);
            val[g.first][g.second]=b;
        }
        comps[a].clear();
    }
}
int main() {
    ans[0]=1;
    scanf("%d %d %d",&n,&m,&q);
    int rc=0;
    int t=max(1000,2000000/n/m)+1000000;
    add=(vector<trm>*)malloc(sizeof(vector<trm>)*t);
    rem=(vector<trm>*)malloc(sizeof(vector<trm>)*t);
    ost=(vector<pair<short,short> >*)malloc(sizeof(vector<pair<short,short> >)*t);
    for(int i=0;i<q;i++) {
        scanf("%d %d %d",&x,&y,&c);
        x--;
        y--;
        rc=c;
        if(c>=t) {
            printf("%d %d\n",c,t);
            return 0;
        }
        if(a[x][y]!=c) {
            add[c].push_back({i+1,x,y});
            rem[a[x][y]].push_back({-i-1,x,y});
        }
        a[x][y]=c;
    }
    rc++;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            ost[a[i][j]].push_back({i,j});
        }
    }
    for(int k=0;k<=rc;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                val[i][j]=-1;
            }
        }
        for(int i=0;i<=cc;i++) comps[i].clear();
        cc=0;
        for(auto g:add[k]) {
            ans[g.i]++;
            int x=g.x;
            int y=g.y;
            val[x][y]=cc++;
            //cout<<comps[val[x][y]].size()<<endl;
            comps[val[x][y]].push_back({x,y});
            if(x>0 && val[x-1][y]!=-1) unite(val[x][y],val[x-1][y],g.i);
            if(y>0 && val[x][y-1]!=-1) unite(val[x][y],val[x][y-1],g.i);
            if(x<n-1 && val[x+1][y]!=-1) unite(val[x][y],val[x+1][y],g.i);
            if(y<m-1 && val[x][y+1]!=-1) unite(val[x][y],val[x][y+1],g.i);


             /*cout<<k<<" "<<cc<<endl;
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    cout<<val[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl<<endl;*/
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                val[i][j]=-1;
            }
        }
        for(int i=0;i<=cc;i++) comps[i].clear();
        cc=0;
        for(auto g:ost[k]) {
            ans[q+1]++;
            int x=g.first;
            int y=g.second;
            val[x][y]=cc++;
            comps[val[x][y]].push_back({x,y});
            if(x>0 && val[x-1][y]!=-1) unite(val[x][y],val[x-1][y],q+1);
            if(y>0 && val[x][y-1]!=-1) unite(val[x][y],val[x][y-1],q+1);
            if(x<n-1 && val[x+1][y]!=-1) unite(val[x][y],val[x+1][y],q+1);
            if(y<m-1 && val[x][y+1]!=-1) unite(val[x][y],val[x][y+1],q+1);


        }
        reverse(rem[k].begin(),rem[k].end());
        for(auto g:rem[k]) {
            ans[-g.i]--;
            int x=g.x;
            int y=g.y;
            val[x][y]=cc++;
            comps[val[x][y]].push_back({x,y});
            if(x>0 && val[x-1][y]!=-1) unite(val[x][y],val[x-1][y],g.i);
            if(y>0 && val[x][y-1]!=-1) unite(val[x][y],val[x][y-1],g.i);
            if(x<n-1 && val[x+1][y]!=-1) unite(val[x][y],val[x+1][y],g.i);
            if(y<m-1 && val[x][y+1]!=-1) unite(val[x][y],val[x][y+1],g.i);
        }
        for(int i=0;i<=cc;i++) comps[i].clear();
        /*printf("~~~\n");
        int t=ans[0];
        for(int i=1;i<=q;i++) {
            t=t+ans[i];
            printf("%d ",t);
        }
        printf("\n~~~\n\n");*/
    }
    for(int i=1;i<=q;i++) {
        ans[i]+=ans[i-1];
        printf("%d\n",ans[i]);
    }
    return 0;
}