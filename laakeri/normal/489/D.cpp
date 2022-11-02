#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll lol[3001][3001];

vector<int> to[3001];
vector<int> from[3001];

int es[3001][3001];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        to[a].push_back(b);
        from[b].push_back(a);
        es[a][b]=1;
    }
    for (int i=1;i<=n;i++){
        for (int ii=0;ii<to[i].size();ii++){
            for (int iii=ii+1;iii<to[i].size();iii++){
                int mi=min(to[i][ii], to[i][iii]);
                int ma=max(to[i][ii], to[i][iii]);
                lol[mi][ma]++;
            }
        }
    }
    ll v=0;
    for (int i=1;i<=n;i++){
        for (int ii=0;ii<from[i].size();ii++){
            for (int iii=ii+1;iii<from[i].size();iii++){
                int mi=min(from[i][ii], from[i][iii]);
                int ma=max(from[i][ii], from[i][iii]);
                v+=lol[mi][ma];
            }
        }
    }
    for (int i=1;i<=n;i++){
        ll lols=0;
        for (int ii=1;ii<=n;ii++){
            if (i!=ii){
                if (es[i][ii]&&es[ii][i]){
                    lols++;
                }
            }
        }
        v-=(lols*(lols-1ll))/2ll;
    }
    cout<<v<<endl;
}