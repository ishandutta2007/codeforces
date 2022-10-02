#include <bits/stdc++.h>

#define int long long
#define f first

#define s second
using namespace std;

template<typename T> using vc = vector<T>;
using pii=pair<int, int>;

vc <vc <int > > adi;
vc <int> vis;
int mod=998244353;
int plu(int a, int b){
    return (a+b)%mod;
}
int mal(int a, int b){
    return (a*b)%mod;
}
vc <int> dfs (int node){
    vis[node]=1;
    vc <int> res={1, 0, 0};
    int anz=0;
    for (auto next: adi[node]){
        //cout << "node " << node << " next " << next << endl;

        if (vis[next]>0) continue;
        anz++;
        auto cur=dfs(next);
        vc <int> c_res(3);
        c_res[0]=mal(res[0], plu(cur[0], cur[2]));
        c_res[1]=plu( mal(res[1], plu(cur[0], cur[2])), mal(res[0] , plu(cur[1], cur[2])));
        c_res[2]=plu(mal(res[2], plu(2*cur[2], cur[1]+cur[0]))  ,    mal(res[1], plu(cur[1], cur[2])));
       // c_res[2]=(res[2]*((cur[0]+cur[1]+cur[2])%mod)+(res[1]*(cur[1]+cur[2]))%mod) % mod;
        res=c_res;
       // cout << res[0] << " " << res[1] << " " << res[2] << endl;
    }
    if (anz==0){
        res={1, 1, 0};
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL_RUN
    freopen("inputf.txt", "r", stdin);
    int ttt;
    cin >> ttt;
    while(ttt--){
    #endif // LOCAL_RUN


    int n;
    cin >> n;
    adi=vc <vc <int> > (n);
    vis=vc <int> (n, -1);
    int temp, tamp;
    for (int i=0; i+1<n; i++){
        cin >> tamp;
         tamp--;
        adi[tamp].push_back(i+1);
    }
    auto res=dfs(0);
    //cout << "in the end" << endl;
   // cout << res[0] << " " << res[1] << " " << res[2] << endl;
    cout << (res[0]+res[2])%mod << "\n";


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
}