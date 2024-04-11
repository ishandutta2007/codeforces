// 

#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,xs=0;
    cin>>n;
    int mat[n][31];
    for(int i=0,x;i<n;i++){
        cin>>x;
        xs^=x;
        for(int j=0;j<31;j++)mat[i][j]=((xs&(1<<j))>0);
    }
    if(!xs){
        cout<<"-1\n";
        return 0;
    }
    // gaussian elimination
    int z=0;
    for(int i=0;i<31;i++){
        for(int j=z;j<n;j++){
            if(mat[j][i]){
                swap(mat[j],mat[z]);
                for(int k=z+1;k<n;k++){
                    if(mat[k][i]){
                        for(int l=0;l<31;l++)mat[k][l]^=mat[z][l];
                    }
                }
                z++;
                break;
            }
        }
    }
    cout<<z<<"\n";
}