#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int used[101010];

vector<int> g[101010];

pair<int, int> dfs1(int x){
    if (used[x]) return {0, 0};
    used[x]=1;
    pair<int, int> r;
    if (g[x].size()==1){
        r={1, x};
    }
    else{
        r={1, 0};
    }
    for (int nx:g[x]){
        auto asd=dfs1(nx);
        r.F+=asd.F;
        r.S=max(r.S, asd.S);
    }
    return r;
}

void dfs2(int x, vector<int>&lol){
    if (used[x]==2) return;
    used[x]=2;
    lol.push_back(x);
    for (int nx:g[x]){
        dfs2(nx, lol);
    }
}

int cmp(const vector<int>&a, const vector<int>&b){
    return a.size()>b.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<vector<int> > cis;
    vector<vector<int> > chs;
    int f=0;
    for (int i=1;i<=n;i++){
        if (used[i]==0){
            auto asd=dfs1(i);
            vector<int> lol;
            if (asd.S){
                dfs2(asd.S, lol);
            }
            else{
                dfs2(i, lol);
            }
            if (asd.S){
                chs.push_back(lol);
            }
            else{
                cis.push_back(lol);
            }
            if (lol.size()>4){
                f=1;
            }
        }
    }
    if (f==1){
        vector<vector<int> > asd;
        for (auto&t:cis){
            int ts=t.size();
            if (ts>4){
                vector<int> lol;
                if (ts%2==0){
                    for (int i=0;i<ts;i+=2){
                        lol.push_back(t[i]);
                    }
                    for (int i=0;i<ts;i+=2){
                        lol.push_back(t[(1-i+2*ts)%ts]);
                    }
                }
                else{
                    for (int i=0;i<ts;i+=2){
                        lol.push_back(t[i]);
                    }
                    for (int i=1;i<ts;i+=2){
                        lol.push_back(t[i]);
                    }
                }
                asd.push_back(lol);
            }
            else{
                asd.push_back(t);
            }
        }
        for (auto&t:chs){
            int ts=t.size();
            if (ts>4){
                vector<int> lol;
                for (int i=0;i<ts;i+=2){
                    lol.push_back(t[i]);
                }
                for (int i=1;i<ts;i+=2){
                    lol.push_back(t[i]);
                }
                asd.push_back(lol);
            }
            else{
                asd.push_back(t);
            }
        }
        sort(asd.begin(), asd.end(), cmp);
        vector<int> vv;
        int ff=1;
        while (ff){
            ff=0;
            for (int i=0;i<(int)asd.size();i++){
                if (asd[i].size()==0) break;
                vv.push_back(asd[i].back());
                asd[i].pop_back();
                ff=1;
            }
        }
        for (int i=0;i<m;i++){
            cout<<vv[i]<<" "<<vv[(i+1)%vv.size()]<<'\n';
        }
    }
    else{
        if (n>=9){
            vector<int> vv;
            for (auto&t:chs){
                for (int a:t){
                    vv.push_back(a);
                }
            }
            for (auto&t:cis){
                for (int a:t){
                    vv.push_back(a);
                }
            }
            for (int i=0;i<m;i++){
                cout<<vv[i]<<" "<<vv[(i+4)%vv.size()]<<'\n';
            }
        }
        else{
            vector<int> a(n);
            for (int i=0;i<n;i++){
                a[i]=i+1;
            }
            while (1){
                vector<pair<int, int> > v;
                for (int i=0;i<n;i++){
                    int ff=0;
                    for (int nx:g[a[i]]){
                        if (nx==a[(i+1)%n]){
                            ff=1;
                            break;
                        }
                    }
                    if (ff==0){
                        v.push_back({a[i], a[(i+1)%n]});
                    }
                }
                if (v.size()>=m){
                    for (int i=0;i<m;i++){
                        cout<<v[i].F<<" "<<v[i].S<<endl;
                    }
                    return 0;
                }
                if (!next_permutation(a.begin(), a.end())) break;
            }
            cout<<-1<<endl;
        }
    }
}