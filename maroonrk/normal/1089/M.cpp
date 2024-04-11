#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

#define rep(i,N) for(int i=0;i<(int)N;i++)
#define pb push_back
#define all(c) c.begin(),c.end()
#define show(x) cerr << #x<<" "<<x<<endl
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int N;
bool e[9][9];

int main(){
    cin>>N;
    rep(i,N) rep(j,N){
        int x;
        cin>>x;
        e[i][j] = x;
    }
    rep(i,N) e[i][i] = 1;
    rep(i,N) rep(j,N) rep(k,N) if(e[j][i]&&e[i][k]) e[j][k] = 1;

    VV<int> uf;
    V<bool> done(N,false);
    rep(i,N) if(!done[i]){
        V<int> vs;
        rep(j,N) if(e[i][j] && e[j][i]){
            done[j] = 1;
            vs.pb(j);
        }
        uf.pb(vs);
    }
    int K = uf.size();
    show(K);
    V<int> ord(K);
    {
        rep(i, K) ord[i] = i;
        bool flag = false;
        do {
            bool ok = true;
            rep(i,K) rep(j,i) if(e[uf[ord[i]].front()][uf[ord[j]].front()]) ok = false;
            if(ok){
                flag = true;
                break;
            }
        }while(next_permutation(all(ord)));
        assert(flag);
    }
    char s[40][40][40];
    int H = 40, W = 40, Z = 2*K;
    rep(k,Z){
        rep(i,H) rep(j,W) s[k][i][j] = (k%2==0 ? '.' : '#');
    }
    using P = pair<int,int>;
    V<P> ps;
    rep(i,H) rep(j,W) if(i%4==1 && j%4==1) ps.pb(P(i,j));
    rep(k,K){
        V<int> vs = uf[ord[k]];
        rep(i,vs.size()){
            int x = ps[ps.size()-1-i].first, y = ps[ps.size()-1-i].second;
            s[k*2][x][y] = '1' + vs[i];
        }
    }
    int I = 0;
    rep(i,K) rep(j,K) if(i!=j) if(e[uf[ord[i]].front()][uf[ord[j]].front()]){
        int x = ps[I].first, y = ps[I].second;
        for(int k=2*i+1;k<=2*j-1;k++){
            for(int dx=-1;dx<=1;dx++) for(int dy=-1;dy<=1;dy++) s[k][x+dx][y+dy] = '#';
            s[k][x][y] = '.';
        }
        I++;
    }
    cout<<W<<" "<<H<<" "<<Z<<endl;
    rep(k,Z){
        rep(i,H){
            rep(j,W){
                cout<<s[k][i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
}