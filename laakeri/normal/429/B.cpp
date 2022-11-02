#include <iostream>

using namespace std;

typedef long long ll;

ll v[1002][1002];

ll dpul[1002][1002];
ll dpur[1002][1002];
ll dpdl[1002][1002];
ll dpdr[1002][1002];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            cin>>v[i][ii];
        }
    }
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            dpul[i][ii]+=v[i][ii];
            dpul[i][ii+1]=max(dpul[i][ii+1],dpul[i][ii]);
            dpul[i+1][ii]=max(dpul[i+1][ii],dpul[i][ii]);
        }
    }

    for (int i=0;i<n;i++){
        for (int ii=m-1;ii>=0;ii--){
            dpur[i][ii]+=v[i][ii];
            if (ii>0) dpur[i][ii-1]=max(dpur[i][ii-1],dpur[i][ii]);
            dpur[i+1][ii]=max(dpur[i+1][ii],dpur[i][ii]);
        }
    }

    for (int i=n-1;i>=0;i--){
        for (int ii=0;ii<m;ii++){
            dpdl[i][ii]+=v[i][ii];
            dpdl[i][ii+1]=max(dpdl[i][ii+1],dpdl[i][ii]);
            if (i>0) dpdl[i-1][ii]=max(dpdl[i-1][ii],dpdl[i][ii]);
        }
    }

    for (int i=n-1;i>=0;i--){
        for (int ii=m-1;ii>=0;ii--){
            dpdr[i][ii]+=v[i][ii];
            if (ii>0) dpdr[i][ii-1]=max(dpdr[i][ii-1],dpdr[i][ii]);
            if (i>0) dpdr[i-1][ii]=max(dpdr[i-1][ii],dpdr[i][ii]);
        }
    }
    ll v=0;
    for (int i=1;i<n-1;i++){
        for (int ii=1;ii<m-1;ii++){
            v=max(v,dpul[i][ii-1]+dpur[i-1][ii]+dpdr[i][ii+1]+dpdl[i+1][ii]);
            v=max(v,dpul[i-1][ii]+dpur[i][ii+1]+dpdr[i+1][ii]+dpdl[i][ii-1]);
        }
    }
    cout <<v<<endl;
}