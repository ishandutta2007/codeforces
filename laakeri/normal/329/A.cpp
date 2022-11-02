#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int fx[111];
int fy[111];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        string t;
        cin>>t;
        for (int ii=1;ii<=n;ii++){
            if (t[ii-1]=='.'){
                fx[i]=ii;
                fy[ii]=i;
            }
        }
    }
    int f=0;
    for (int i=1;i<=n;i++){
        if (fx[i]==0){
            f=1;
            break;
        }
    }
    if (!f){
        for (int i=1;i<=n;i++){
            cout<<i<<" "<<fx[i]<<'\n';
        }
        return 0;
    }
    f=0;
    for (int i=1;i<=n;i++){
        if (fy[i]==0){
            f=1;
            break;
        }
    }
    if (!f){
        for (int i=1;i<=n;i++){
            cout<<fy[i]<<" "<<i<<'\n';
        }
        return 0;
    }
    cout<<-1<<endl;
}