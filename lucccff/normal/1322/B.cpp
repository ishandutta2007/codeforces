#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,s,x;
    int a[20000000],d[20000000];
    long long c[30],ans[30];
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    memset(ans,0,sizeof(ans));
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>k;
        a[k]+=1;
        for(j=0;j<24;j++) {
            c[j]+=(k&1)*(n-1);
            k>>=1;
        }
    }
    x=1<<24;
    s=1;
    for(i=0;i<24;i++) {
        s<<=1;
        for(j=0;j<s;j++) {
            d[j]=0;
        }
        d[s]=0;
        for(j=0;j<x;j++) {
            d[j&(s-1)]+=a[j];
        }
        k=0;
        l=0;
        for(j=0;j<s;j++) {
            k+=d[s-j];
            l+=k*d[j];
        }
        for(j=0;j<(s>>1);j++) {
            l-=d[s-j-1];
        }
        c[i+1]+=l/2;
    }
    l=0;
    for(i=24;i>=0;i--) {
        l=(l<<1)+(c[i]&1);
    }
    cout<<l;
    return 0;
}