#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,I,pre[maxn],suf[maxn];
vector<int> x;

int main(){
    scanf("%d%d",&n,&I);
    I*=8;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a.begin(),a.end());
    vector<int> b=a;
    b.erase(unique(b.begin(),b.end()),b.end());
    int c=I/n;
    int p=0,k=1;
    for(int i=0;i<c;i++){
        k*=2;
        if(k>=1e9)break;
    }
    if((int)b.size()<=k){
        return !printf("0");
    }
    vector<int> d;
    d.push_back(0);
    for(int i=0;i<n;i++){
        int j=i;
        while(j+1<n&&a[j+1]==a[i]){
            j++;
        }
        d.push_back(j-i+1);
        i=j;
    }
    int mi=(int)b.size()-k;
    n=(int)d.size()-1;
    d.push_back(0);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+d[i];
    }
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1]+d[i];
    }
    int ans=1e9;
    for(int i=0;i<=mi;i++){
        ans=min(ans,pre[i]+suf[n-mi+i+1]);
    }
    printf("%d\n",ans);
}
/*
    Good Luck
        -Lysithea
*/