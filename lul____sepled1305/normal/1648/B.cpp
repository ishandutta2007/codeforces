//
// Created by Nitit Jongsawatsataporn on 16/3/2022 AD.
//

#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n,c; cin>>n>>c;
        int C[c+1], A[n];
        for(int i=0;i<=c;i++) C[i] = 0;
        for(int i=0;i<n;i++) {
            cin>>A[i];
            C[A[i]]++;
        }
        for(int i=1;i<=c;i++) {
            C[i] += C[i-1];
        }
        bool pass = true;
        for(int i=1;i<=c;i++) {
            if(C[i]-C[i-1] > 0) {
                //Exists
                for(int j=1;j<=c/i;j++) {
                    //if(j*i > c) continue;
                    int nn;
                    nn = C[min(c,i*(j+1)-1)] - C[j*i-1];
                    if(nn > 0) {
                        //cout<<i<<' '<<j<<' '<<pass<<' '<<nn<<endl;
                        pass &= (C[j]-C[j-1] > 0);
                    }
                }
            }
        }
        if(pass) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}