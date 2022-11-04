#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[555][555],b[555][555],c[555][555];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&b[i][j]);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) c[i][j]=a[i][j]^b[i][j];
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=m;j++) cnt+=c[i][j];
        if(cnt%2) return !printf("No");
    }

    for(int i=1;i<=m;i++){
        int cnt=0;
        for(int j=1;j<=n;j++) cnt+=c[j][i];
        if(cnt%2) return !printf("No");
    }
    printf("Yes");
}