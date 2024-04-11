#include <bits/stdc++.h>
using namespace std;

int a[100010],b[100010];
long long n,m;
void pack1(long long x, int y, int k) {
    for(int i=m-x/100000;i>=0;i--) {
        if (a[i]!=-1) {
            //long long s=i-(x+(long long)99999)/(long long)100000;
            //if (s>0) b[s]=-1;
            //if (b[i]!=-1){
                long long l=((x+(long long)99999)/(long long)100000+i);
                for(int j=1;j<=y&&l<=m;j++) {
                    if (a[l]==-1) a[l]=k;
                    else break;
                    l=(long long)((x+(long long)99999)/(long long)100000+l);
                }
            //}
        }
    }
}

void pack2(long long x, int y, int k) {
    for(int i=(long long)m*100000/x;i>=1;i--) {
        if (a[i]!=-1) {
            //long long s=(i*100000)/x;
            //if (s>0) if ((s*x+(long long)99999)/(long long)100000==i) b[s]=-1;
            //if (b[i]!=-1){
                long long l=i;
                int j=1;
                l=(l*x+(long long)99999)/(long long)100000;
                while ((j<=y)&&(l<=m)) {
                    if (a[l]==-1) a[l]=k;
                    else break;
                    l=(l*x+(long long)99999)/(long long)100000;
                    j++;
                }
            //}
        }
    }
}

int main(){
    int i,j,k,l,y;
    long long x;
    memset(a,-1,sizeof(a));
    a[0]=0;
    cin>>n>>m;
    for(i=0;i<n;i++) {
        cin>>l>>x>>y;
        //for(j=1;j<=m;j++) b[j]=0;
        if (l==1) pack1(x,y,i+1);
        else pack2(x,y,i+1);
    }
    for(i=1;i<=m;i++) cout<<a[i]<<' ';
    return 0;
}