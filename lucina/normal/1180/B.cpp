#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,mi;
pair<int,int> a[maxn];
bool z,ch[maxn];
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.second<y.second;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].first);
        a[i].second=i;
        if(a[i].first<0){
            mi++;
        }
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i].first>=0){
            a[i].first=-a[i].first-1;
            mi++;
            ch[i]=true;
        }
    }
    if((mi&1)==0){
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++)
            printf("%d ",a[i].first);
            return 0;
    }
    else{
        int mid1=-1,mid2=-1;
        int mi=1e9,ma=-1e9;
        for(int i=1;i<=n;i++){
            if(a[i].first<mi)
                mi=a[i].first,mid1=i;
            if(a[i].first>ma)
                ma=a[i].first,mid2=i;
        }
        a[mid1].first=-a[mid1].first-1;
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++)
            printf("%d ",a[i].first);
    }
}