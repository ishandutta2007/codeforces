#include <bits/stdc++.h>
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef complex<ll> co;

int pa[101010][19];
int d[101010];

bool ccw(co a, co b, co c) {
	return ((c-a)*conj(b-a)).Y>0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<co> p(n+1);
    for (int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        p[i]={x, y};
    }
    for (int i=n-1;i>=1;i--){
        pa[i][0]=i+1;
        while (pa[i][0]!=n){
            int t=pa[pa[i][0]][0];
            if (ccw(p[i], p[pa[i][0]], p[t])){
                pa[i][0]=pa[pa[i][0]][0];
            }
            else{
                break;
            }
        }
        d[i]=d[pa[i][0]]+1;
    }
    for (int k=1;k<19;k++){
        for (int i=1;i<=n;i++){
            pa[i][k]=pa[pa[i][k-1]][k-1];
        }
    }
    int q;
    cin>>q;
    for (int qq=0;qq<q;qq++){
        int a,b;
        cin>>a>>b;
        if (d[a]>d[b]) swap(a, b);
        for (int i=18;i>=0;i--){
            if (d[b]-d[a]>=(1<<i)){
                b=pa[b][i];
            }
        }
        if (a==b){
            cout<<a<<" ";
            continue;
        }
        for (int i=18;i>=0;i--){
            if (pa[a][i]!=pa[b][i]){
                a=pa[a][i];
                b=pa[b][i];
            }
        }
        cout<<pa[a][0]<<" ";
    }
}