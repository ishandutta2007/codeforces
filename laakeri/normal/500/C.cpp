#include <iostream>

using namespace std;

int w[501];

int b[1001];

int f[501];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>w[i+1];
    }
    int v=0;
    for (int i=0;i<m;i++){
        cin>>b[i];
        for (int i=1;i<=n;i++) f[i]=0;
        for (int ii=i-1;ii>=0;ii--){
            if (b[ii]==b[i]) break;
            if (!f[b[ii]]){
                v+=w[b[ii]];
                f[b[ii]]=1;
            }
        }
    }
    cout<<v<<endl;
}