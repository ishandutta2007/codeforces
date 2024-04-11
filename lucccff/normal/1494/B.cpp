#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,m,n,t,a[4],b[4],f;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>a[0]>>a[1]>>a[2]>>a[3];
        if ((a[0]<=n)&&(a[1]<=n)&&(a[2]<=n)&&(a[3]<=n)){
            f=0;
            for(j=0;j<16;j++){
                for(k=0;k<4;k++){
                    b[k]=a[k];
                }
                m=j;
                for(k=0;k<4;k++){
                    b[k]-=m%2;
                    b[(k+1)%4]-=m%2;
                    m=m/2;
                }
                m=0;
                for(k=0;k<4;k++){
                    if ((b[k]<0)||(b[k]>n-2)) m=1;
                }
                if (m==0) f=1;
            }
            if (f) {
                cout<<"YES";
            }
            else {
                cout<<"NO";
            }
        }
        else {
            cout<<"NO";
        }
        cout<<endl;
    }

    return 0;
}