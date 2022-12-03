#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,x,h,y,z;
    long long a1[100010],a2[100010],a3[100010],a4[100010],a5[100010],b[100010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a1[j]>>a2[j]>>a3[j]>>a4[j]>>a5[j];
            b[j]=j;
        }
        x=1;
        h=0;
        while(x<n) {
            x<<=1;
            h++;
        }
        for(j=n;j<x;j++) {
            a1[j]=a2[j]=a3[j]=a4[j]=a5[j]=1e9;
            b[j]=j;
        }
        y=1;
        for(j=0;j<h;j++) {
            y<<=1;
            for(k=0;k<x;k+=y) {
                z=0;
                if (a1[b[k]]<a1[b[k+(y>>1)]]) z++;
                if (a2[b[k]]<a2[b[k+(y>>1)]]) z++;
                if (a3[b[k]]<a3[b[k+(y>>1)]]) z++;
                if (a4[b[k]]<a4[b[k+(y>>1)]]) z++;
                if (a5[b[k]]<a5[b[k+(y>>1)]]) z++;
                if (z<3) b[k]=b[k+(y>>1)];
            }
        }
        l=b[0];
        for(j=0;j<n;j++) {
            z=0;
            if (a1[l]<=a1[j]) z++;
            if (a2[l]<=a2[j]) z++;
            if (a3[l]<=a3[j]) z++;
            if (a4[l]<=a4[j]) z++;
            if (a5[l]<=a5[j]) z++;
            if (z<3) break;
        }
        if (j==n) cout<<l+1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}