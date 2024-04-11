#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[20],b[10];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL i,j,k,l,m,n,t;
    int ans=0,s;
    cin>>n;
    if (n%25==0) {
        cout<<0<<endl;
        return 0;
    }
    if (n<10) {
        cout<<-1<<endl;
        return 0;
    }
    m=0;
    while(n) {
        a[m++]=n%10;
        n/=10;
    }
    for(i=0;i<10;i++) b[i]=-1;
    for(i=m-1;i>=0;i--) {
        b[a[i]]=i;
    }
    k=0;
    while(k<m&&a[k]!=0) k++;
    if (k<m) {
        ans+=k;
        k++;
        while(k<m&&a[k]!=0) k++;
        if (k<m) {
            ans+=k-1;
        }
        else {
            ans=-1;
        }
    }
    else {
        ans=-1;
    }
    
    if (b[2]>=0&&b[5]>=0) {
        if (b[2]>b[5]) {
            s=b[2]+b[5]-1;
        }
        else {
            s=b[2]+b[5];
            k=m-2;
            if (b[5]==m-1) while(a[k]==0) {
                s++;
                k--;
            }
        }
        if (ans!=-1) ans=min(ans,s);
        else ans=s;
    }
    
    if (b[7]>=0&&b[5]>=0) {
        if (b[7]>b[5]) {
            s=b[7]+b[5]-1;
        }
        else {
            s=b[7]+b[5];
            k=m-2;
            if (b[5]==m-1) while(a[k]==0) {
                s++;
                k--;
            }
        }
        if (ans!=-1) ans=min(ans,s);
        else ans=s;
    }

    if (b[5]>=0&&b[0]>=0) {
        if (b[5]>b[0]) {
            s=b[5]+b[0]-1;
        }
        else {
            s=b[5]+b[0];
        }
        if (ans!=-1) ans=min(ans,s);
        else ans=s;
    }
    cout<<ans<<endl;
    return 0;
}