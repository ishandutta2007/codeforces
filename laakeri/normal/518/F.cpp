#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int ot[2002][2002];
int ob[2002][2002];
int ov[2002][2002];
int oo[2002][2002];
string ma[2002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>ma[i];
    }
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            if (ma[i][ii]=='#') break;
            ov[i][ii]=1;
        }
        for (int ii=m-1;ii>=0;ii--){
            if (ma[i][ii]=='#') break;
            oo[i][ii]=1;
        }
    }
    for (int ii=0;ii<m;ii++){
        for (int i=0;i<n;i++){
            if (ma[i][ii]=='#') break;
            ot[i][ii]=1;
        }
        for (int i=n-1;i>=0;i--){
            if (ma[i][ii]=='#') break;
            ob[i][ii]=1;
        }
    }
    ll v=0;
    for (int i=1;i<n-1;i++){
        ll ok=0;
        ll vi=0;
        for (int ii=1;ii<m-1;ii++){
            ok+=ot[i][ii];
            ok+=ob[i][ii];
            if (ot[i][ii]&&ot[i][ii-1]&&ii-1>0) vi++;
            if (ob[i][ii]&&ob[i][ii-1]&&ii-1>0) vi++;
            if (ot[i][ii]&&ob[i][ii]) vi++;
            if (ma[i][ii]=='#'||ii==m-2){
                v+=ok*(ok-1ll)/2ll;
                v-=vi;
                ok=0;
                vi=0;
            }
        }
    }
    for (int ii=1;ii<m-1;ii++){
        ll ok=0;
        ll vi=0;
        for (int i=1;i<n-1;i++){
            ok+=ov[i][ii];
            ok+=oo[i][ii];
            if (ov[i][ii]&&ov[i-1][ii]&&i-1>0) vi++;
            if (oo[i][ii]&&oo[i-1][ii]&&i-1>0) vi++;
            if (ov[i][ii]&&oo[i][ii]) vi++;
            if (ma[i][ii]=='#'||i==n-2){
                v+=ok*(ok-1ll)/2ll;
                v-=vi;
                ok=0;
                vi=0;
            }
        }
    }
    for (int i=1;i<n-1;i++){
        if (oo[i][0]) v++;
    }
    for (int i=1;i<m-1;i++){
        if (ob[0][i]) v++;
    }
    for (int i=1;i<n-1;i++){
        for (int ii=1;ii<m-1;ii++){
            if (ot[i][ii]){
                v+=(ll)ov[i][ii];
                v+=(ll)oo[i][ii];
            }
            if (ob[i][ii]){
                v+=(ll)ov[i][ii];
                v+=(ll)oo[i][ii];
            }
        }
    }
    cout<<v<<endl;
}