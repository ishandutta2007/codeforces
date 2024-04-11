#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;
int n,k;
pair<pair<int,int>,int> a[100010];
int ans[100010];
int main(){
    scanf("%d%d%*d",&n,&k);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i].first.first);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i].first.second);
        a[i].second=i+1;
    }
    sort(a,a+n);
    double lo=0,hi=n;
    for(int run=0; run<100; run++){
        double mi;
        if(run==99)mi=hi;else
            mi=(lo+hi)/2;
        int j=1;
        for(int i=0; i<n && j<=k; i++)
            if(j<=a[i].first.second*mi)
                ans[j++]=a[i].second;
        if(j>k)
            hi=mi;
        else
            lo=mi;
    }
    for(int j=1; j<=k; j++)
        printf("%d%c",ans[j],j<k?' ':'\n');
    return 0;
}