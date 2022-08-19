#include <iostream>
#include <cstdio>
using namespace std;
int tot,i;
long long ans,n,nn;
inline void DFS(int step,int n0,int n1,long long sum) {
    if (step>tot) {
        if (sum<ans && sum>=nn) ans=sum;
        return;
    }
    if (n0<tot/2) DFS(step+1,n0+1,n1,sum*10+4);
    if (n1<tot/2) DFS(step+1,n0,n1+1,sum*10+7);
}
int main() {
    cin>>n;nn=n;
    for (tot=0;n;) tot++,n/=10;
    if (tot%2==0) {
        for (i=1;i<=tot/2;i++) ans=ans*10+7;
        for (i=1;i<=tot/2;i++) ans=ans*10+4;
    }
    if (tot&1 || (tot%2==0 && nn>ans)) {
        for (i=1;i<=(tot+2)/2;i++) printf("4");
        for (i=1;i<=(tot+2)/2;i++) printf("7");
    } else {
        DFS(1,0,0,0);
        cout<<ans;
    }
}