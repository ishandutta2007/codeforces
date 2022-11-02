#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string ls[1001][10];

int n,m,k,w;

struct e{
    int a,b,d;
    bool operator<(const e&E) const{
        return E.d>d;
    }
};

vector<e> es;
vector<pair<int,int> > v;

int p[1001];

int cpm[1001];

int cp(int x){
    if (p[x]!=x){
        return cp(p[x]);
    }
    return x;
}

vector<int> g[1001];

vector<pair<int,int> > vv;

int used2[1001];

void dfs (int x, int f){
    if (used2[x]) return;
    used2[x]=1;
    vv.push_back(make_pair(x, f));
    for (int nx:g[x]){
        dfs(nx, x);
    }
}

int lols[1001];

int main(){
    cin>>n>>m>>k>>w;
    //n=10;
    //m=10;
    //k=1000;
    for (int i=0;i<k;i++){
        for (int ii=0;ii<n;ii++){
            cin>>ls[i+1][ii];
            //ls[i+1][ii]="..........";
        }
    }
    int lol=n*m;
    for (int i=1;i<=k;i++){
        for (int ii=i+1;ii<=k;ii++){
            int d=0;
            for (int j=0;j<n;j++){
                for (int jj=0;jj<m;jj++){
                    if (ls[i][j][jj]!=ls[ii][j][jj]){
                        d++;
                        if (d*w>=lol) break;
                    }
                }
                if (d*w>=lol) break;
            }
            if (d*w<lol){
                e ed;
                ed.a=i;
                ed.b=ii;
                ed.d=d;
                es.push_back(ed);
            }
        }
    }
    sort(es.begin(),es.end());
    for (int i=1;i<=k;i++) p[i]=i;
    int v=0;
    int ff=0;
    for (auto ed:es){
        int ca=cp(ed.a);
        int cb=cp(ed.b);
        if (ca!=cb){
            ff++;
            g[ed.a].push_back(ed.b);
            g[ed.b].push_back(ed.a);
            v+=ed.d*w;
            if (cpm[p[ca]]<cpm[p[cb]]){
                p[ca]=p[cb];
                cpm[p[cb]]+=cpm[p[ca]];
            }
            else{
                p[cb]=p[ca];
                cpm[p[ca]]+=cpm[p[cb]];
            }
            if (ff==k-1) break;
        }
    }
    for (int i=1;i<=k;i++){
        if (used2[i]==0){
            dfs(i, 0);
            v+=n*m;
        }
    }
    cout<<v<<endl;
    for (auto pp:vv){
        cout<<pp.first<<" "<<pp.second<<endl;
    }
}