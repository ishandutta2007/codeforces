#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn];

int main(){
    scanf("%d",&n);
    if(n%2==0){
        return !printf("NO\n");
    }
    printf("YES\n");
    a[1]=1;
    int pt=2,l=2,r=n+1;
    while(true){
        if(r>2*n)
        break;
        a[r++]=pt++;
        if(pt>2*n)break;
        if(r>2*n)break;
        a[r++]=pt++;
        if(pt>2*n)break;
        if(l>n)break;
        a[l++]=pt++;
        if(l>n)break;
        a[l++]=pt++;
    }
 /*   long long sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
    }
    vector<long long> aa;
    aa.push_back(sum);
    for(int i=1;i<=2*n;i++){
        sum-=a[i];
        int idx=i+n;
        if(idx>2*n)idx-=2*n;
        sum+=a[idx];
        aa.push_back(sum);
    }
    sort(aa.begin(),aa.end());
   assert(abs(aa[0]-aa.back())<=1);*/
    for(int i=1;i<=2*n;i++){
        printf("%d ",a[i]);
    }

}
/*
    Good Luck
        -Lucina
*/