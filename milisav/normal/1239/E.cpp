#include<bits/stdc++.h>
#define maxi 1250001
#define maxt 50000
using namespace std;
int n;
int a[100];
int b[10][30];
bool vis[100];
vector<int> x;
vector<int> y;
short c[36][1250001];
int main() {
    scanf("%d",&n);
    for(int i=0;i<2*n;i++) scanf("%d",&a[i]);
    sort(a,a+2*n);
    b[1][1]=a[0];
    b[2][n]=a[1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=maxi;j++) c[i][j]=-1;
    }
    c[0][0]=0;
    int s=0;
    for(int k=2;k<2*n;k++) {
        s+=a[k];
        for(int i=n-1;i>0;i--) {
            int r=i*maxt;
            for(int j=a[k];j<=r;j++) {
                if(c[i][j]==-1 && c[i-1][j-a[k]]!=-1) c[i][j]=k;
            }
        }
    }
    int p=(s+1)/2;
    while(c[n-1][p]==-1) p++;
    int t=n-1;
    while(t>0) {
        vis[c[t][p]]=true;
        p=p-a[c[t][p]];
        t--;
    }
    for(int k=2;k<2*n;k++) {
        if(vis[k]) x.push_back(a[k]);
        else y.push_back(a[k]);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(int i=0;i<n-1;i++) {
        b[2][n-i-1]=x[i];
        b[1][i+2]=y[i];
    }
    for(int i=1;i<=2;i++) {
        for(int j=1;j<=n;j++) printf("%d ",b[i][j]);
        printf("\n");
    }
    return 0;
}