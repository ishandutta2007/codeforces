#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int u[55];
int v[55];

int a[55][55];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<n;ii++){
            cin>>a[i][ii];
        }
    }
    for (int i=1;i<n;i++){
        for (int ii=0;ii<n;ii++){
            if (u[ii]==0){
                int f=1;
                for (int iii=0;iii<n;iii++){
                    if (u[iii]==0&&ii!=iii){
                        if (a[ii][iii]!=i){
                            f=0;
                            break;
                        }
                    }
                }
                if (f==1){
                    v[ii]=i;
                    u[ii]=1;
                    goto taa;
                }
            }
        }
        taa:;
    }
    for (int i=0;i<n;i++){
        if (v[i]==0) v[i]=n;
        cout<<v[i]<<" ";
    }
}