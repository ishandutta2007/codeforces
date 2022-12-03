#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,f;
    int a[100][100];
    char ch;
    cin>>t;
    for(int p=0;p<t;p++) {
        cin>>n>>m;
        k=-1;
        for(i=0;i<n;i++) {
            getchar();
            for(j=0;j<m;j++) {
                ch=getchar();
                if (ch=='.') {
                    a[i][j]=-1;
                }
                else if (ch=='R') {
                    a[i][j]=1;
                    k=(i+j+1)&1;
                }
                else {
                    a[i][j]=0;
                    k=(i+j)&1;
                }
            }
        }
        if (k==-1) {
            cout<<"YES"<<endl;
            for(i=0;i<n;i++) {
                for(j=0;j<m;j++) {
                    if ((i+j)&1) cout<<'R';
                    else cout<<'W';
                }
                cout<<endl;
            }
        }
        else {
            f=0;
            for(i=0;i<n;i++) {
                for(j=0;j<m;j++) {
                    if (a[i][j]>=0&&(((i+j+a[i][j])&1)!=k)) {
                        f=1;
                        break;
                    }
                }
                if (f==1) break;
            }
            if (f) {
                cout<<"NO\n";
            }
            else {
                cout<<"YES\n";
                for(i=0;i<n;i++) {
                    for(j=0;j<m;j++) {
                        if ((i+j+k)&1) cout<<'R';
                        else cout<<'W';
                    }
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}