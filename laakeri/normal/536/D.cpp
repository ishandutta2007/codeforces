#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll d[2020][2];
ll dd[2020][2];
ll p[2020];
vector<pair<int, ll> > g[2020];
vector<int> cs[2];
ll dp[2020][2020][2];
int r[2020][2];

ll best1[2020];
ll best2[2020];

int n,m;
int valid(int a, int b){
    if (a>0&&a<n){
        if (dd[a-1][0]==dd[a][0]) return 0;
    }
    if (b>0&&b<n){
        if (dd[b-1][1]==dd[b][1]) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int s,t;
    cin>>s>>t;
    for (int i=1;i<=n;i++){
        cin>>p[i];
    }
    for (int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    for (int i=0;i<2;i++){
        priority_queue<pair<ll, int> > dij;
        if (i==0) dij.push({-1, s});
        else dij.push({-1, t});
        while (!dij.empty()){
            auto x=dij.top();
            dij.pop();
            if (d[x.S][i]) continue;
            r[x.S][i]=(int)cs[i].size();
            dd[(int)cs[i].size()][i]=-x.F;
            cs[i].push_back(x.S);
            d[x.S][i]=-x.F;
            for (auto nx:g[x.S]){
                dij.push({x.F-nx.S, nx.F});
            }
        }
    }
    //0, nyt on ekan vuoro
    for (int i=n-1;i>=0;i--){
        for (int ii=n-1;ii>=0;ii--){
            if (valid(i, ii)){
                //0
                ll su=0;
                int f=0;

                for (int j=i+1;j<=n;j++){
                    if (r[cs[0][j-1]][1]>=ii){
                        best1[ii]+=p[cs[0][j-1]];
                        su+=p[cs[0][j-1]];
                        f=1;
                    }
                    if (valid(j, ii)){
                        if (f){
                            best1[ii]=max(best1[ii], su-dp[j][ii][1]);
                        }
                        break;
                    }
                }
                dp[i][ii][0]=best1[ii];
                //1
                su=0;
                f=0;
                for (int j=ii+1;j<=n;j++){
                    if (r[cs[1][j-1]][0]>=i){
                        best2[i]+=p[cs[1][j-1]];
                        su+=p[cs[1][j-1]];
                        f=1;
                    }
                    if (valid(i, j)){
                        if (f){
                            best2[i]=max(best2[i], su-dp[i][j][0]);
                        }
                        break;
                    }
                }
                dp[i][ii][1]=best2[i];
                //cout<<i<<" "<<ii<<" "<<dp[i][ii][0]<<" "<<dp[i][ii][1]<<endl;
            }
        }
    }
    if (dp[0][0][0]>0){
        cout<<"Break a heart"<<endl;
    }
    else if (dp[0][0][0]==0){
        cout<<"Flowers"<<endl;
    }
    else{
        cout<<"Cry"<<endl;
    }
}