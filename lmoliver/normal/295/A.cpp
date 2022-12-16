#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100100;
int l[N],r[N],d[N];
LL w[N]={0};
LL a[N]={0};
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--)a[i]-=a[i-1];
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&l[i],&r[i],&d[i]);
    }
    for(int i=0;i<k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        w[x]++,w[y+1]--;
    }
    for(int i=1;i<=m;i++){
        w[i]+=w[i-1];
        LL c=w[i]*d[i];
        a[l[i]]+=c;
        a[r[i]+1]-=c;
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}