#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,r,c,s=0;
    int a[101][101],b[101][101],c1[63];
    char ch;
    cin>>t;
    for(;t>0;t--) {
        cin>>r>>c>>k;
        s=0;
        for(i=0;i<r;i++) {
            getchar();
            for(j=0;j<c;j++) {
                ch=getchar();
                if (ch=='R') a[i][j]=1;
                else a[i][j]=0;
                s+=a[i][j];
            }
        }
        for(i=0;i<k;i++) {
            c1[i]=s/(k-i);
            s=s-c1[i];
        }
        int x=0,y=0;
        for(i=0;i<k;i++) {
            s=0;
            while (s<c1[i]) {
                b[x][y]=i;
                s+=a[x][y];
                if (y%2==0) {
                    if (x<r-1) x++;
                    else y++;
                }
                else {
                    if (x>0) x--;
                    else y++;
                }
            }
        }
        while(y<c){
            b[x][y]=k-1;
            s+=a[x][y];
            if (y%2==0) {
                if (x<r-1) x++;
                else y++;
            }
            else {
                if (x>0) x--;
                else y++;
            }
        }

        for(i=0;i<r;i++) {
            for(j=0;j<c;j++) {
                if (b[i][j]<26) {
                    cout<<(char)('A'+b[i][j]);
                }
                else if (b[i][j]<52) {
                    cout<<(char)('a'+b[i][j]-26);
                }
                else {
                    cout<<b[i][j]-52;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}