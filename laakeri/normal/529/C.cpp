#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

const int N=1<<18;
int st[2*N];
//set<int> lol[N];

vector<int> xs[200101];
vector<int> ys[200101];

vector<pair<pair<int, int>, pair<int, int> > > xqs[200101];
vector<pair<pair<int, int>, pair<int, int> > > yqs[200101];

int v[200101];

void sv(int i, int x){
    st[i+N]=x;
    for (i=(i+N)/2;i;i/=2){
        st[i]=min(st[i*2], st[i*2+1]);
    }
}
int get(int a, int b){
    a+=N;
    b+=N;
    int vv=1e9;
    while (a<=b){
        if (a%2) vv=min(st[a++], vv);
        if (!(b%2)) vv=min(st[b--], vv);
        a/=2;
        b/=2;
    }
    return vv;
}
/*
int delmax(int i, int x){
    lol[i].erase(x);
    if (lol[i].size()>0){
        st[i+N]=(*lol[i].rbegin());
    }
    else{
        st[i+N]=0;
    }
    for (i+=N;i;i/=2){
        st[i]=max(st[i*2], st[i*2+1]);
    }
}*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k,qq;
    cin>>n>>m>>k>>qq;
    for (int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        xs[y].push_back(x);
        ys[x].push_back(y);
    }
    for (int i=0;i<qq;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        xqs[y2].push_back({{x1, x2}, {y1, i}});
        yqs[x2].push_back({{y1, y2}, {x1, i}});
    }
    for (int i=1;i<=m;i++){
        for (int x:xs[i]){
            sv(x, i);
        }
        for (auto q:xqs[i]){
            //cout<<q.F.F<<" "<<q.F.S<<" "<<get(q.F.F, q.F.S)<<" "<<i<<endl;
            if (get(q.F.F, q.F.S)>=q.S.F){
                //cout<<"joo"<<endl;
                v[q.S.S]=1;
            }
        }
    }
    for (int i=0;i<2*N;i++){
        st[i]=0;
    }
    for (int i=1;i<=n;i++){
        for (int y:ys[i]){
            sv(y, i);
        }
        for (auto q:yqs[i]){
            //cout<<q.F.F<<" "<<q.F.S<<" "<<get(q.F.F, q.F.S)<<" "<<i<<endl;
            if (get(q.F.F, q.F.S)>=q.S.F){
                //cout<<"joo"<<endl;
                v[q.S.S]=1;
            }
        }
    }
    for (int i=0;i<qq;i++){
        if (v[i]){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}