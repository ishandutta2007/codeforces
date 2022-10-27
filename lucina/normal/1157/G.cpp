#include<bits/stdc++.h>
using namespace std;
int a[205][205],n,m,b[205][205],s;
void invert(int row,int col){
    if(row){
     for(int j=1;j<=m;j++)
            b[row][j]^=1;
    return;
    }
    if(col){
        for(int j=1;j<=n;j++)
            b[j][col]^=1;
    return;
    }
}
int sorted(int row){
    bool ch=true;
    for(int i=2;i<=m;i++)
        ch&=(b[row][i]>=b[row][i-1]);
    if(ch)return 1;
    ch=true;
    for(int i=2;i<=m;i++)
        ch&=(b[row][i]<=b[row][i-1]);
    if(ch)return 2;
    return 0;
}
bool same(int row){
    bool quick=true;
    for(int i=2;i<=m;i++)
        quick&=(b[row][i]==b[row][1]);
    return quick;
}
void test(int x,bool flag){
    vector<int> d(n+1,0),c(m+1,0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        b[i][j]=a[i][j];
    if(flag){
        for(int i=1;i<=x;i++)
            if(b[1][i]==1)
            invert(0,i),c[i]=1;
        for(int i=x+1;i<=m;i++)
            if(b[1][i]==0)
            invert(0,i),c[i]=1;
    }
    else{
        for(int i=1;i<=x;i++)
        if(b[1][i]==0)
        invert(0,i),c[i]=1;
        for(int i=x+1;i<=m;i++)
            if(b[1][i]==1)
            invert(0,i),c[i]=1;
    }
    if(!flag)d[1]=1,invert(1,0);
    int last=b[1][m];
    for(int i=2;i<=n;i++){
        s=sorted(i);
        if(s==0)return;
        if(same(i)){
            if(last==0&&b[i][1]==1)
                d[i]=1,last=0;
            if(last==1&&b[i][1]==0)
                d[i]=1,last=1;
            continue;
        }
        if(last==1)return;
        if(last==0&&s==2){
            d[i]=1;last=1;
        }
        last=1;
    }
    printf("YES\n");
    for(int i=1;i<=n;i++){printf("%d",d[i]);
    }
    printf("\n");
    for(int i=1;i<=m;i++){printf("%d",c[i]);
    }
    printf("\n");
    exit(0);
    return;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=0;i<=m;i++)
        for(int j=0;j<2;j++)
        test(i,j);
    printf("NO\n");


}