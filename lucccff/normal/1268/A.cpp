#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
    long long i,j,k,l,m,n,t;
    long long a[200010],b[200010];
    cin>>n>>k;
    getchar();
    for(i=0;i<n;i++) {
        a[i]=getchar()-'0';
    }
    for(i=0;i<k;i++) {
        b[i]=a[i];
    }
    t=1;
    for(i=k;i<n;i++) {
        if (a[i]<b[i%k]) {
            break;
        }
        else if (a[i]>b[i%k]) {
            t=0;
            break;
        }
    }
    if (!t) {
        j=k-1;
        b[j]++;
        while(b[j]==10) {
            b[j]-=10;
            j--;
            b[j]++;
        }
    }
    cout<<n<<endl;
    for(i=0;i<n;i++) cout<<b[i%k];
    return 0;
}