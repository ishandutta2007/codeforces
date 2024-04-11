#include <iostream>

using namespace std;

int c[1101];
int w[301];

int b[1101];

int m,t,r;

int v=0;

int lc(int i){
    if (c[i]==1) return 0;
    else {
        v++;
        c[i]=1;
        for (int ii=i;ii<i+t;ii++){
            b[ii]++;
        }
        return 1;
    }
}

int main(){
    cin>>m>>t>>r;
    for (int i=0;i<m;i++){
        cin>>w[i];
        w[i]+=350;
    }
    for (int i=m-1;i>=0;i--){
        int ii=w[i]-t+1;
        while (b[w[i]]<r&&ii<=w[i]){
            lc(ii);
            ii++;
        }
        if (b[w[i]]<r){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<v<<endl;
}