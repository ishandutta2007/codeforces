#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

multiset<int> c[5];
ll n,m,k;

int v[5];

int ok(){
    ll co=0;
    for (int i=0;i<m;i++){
        co+=(*c[i].rbegin());
    }
    return co<=k;
}

ll va[100001][5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    int ak=0;
    int vv=0;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            cin>>va[i][ii];
            c[ii].insert(va[i][ii]);
        }
        while (ak<i&&ok()==0){
            for (int ii=0;ii<m;ii++){
                c[ii].erase(c[ii].find(va[ak][ii]));
            }
            ak++;
        }
        if (ok()&&i-ak+1>vv){
            for (int ii=0;ii<m;ii++){
                v[ii]=(*c[ii].rbegin());
            }
            vv=i-ak+1;
        }
    }
    for (int i=0;i<m;i++){
        cout<<v[i]<<" ";
    }
}