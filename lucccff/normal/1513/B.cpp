#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long inv(long long a){
    if (a == 1) return 1;
    long long m=MOD;
    return inv(m%a)*(m-m/a)%m;
}

long long jie(int n) {
    long long k=1;
    for(int i=1;i<=n;i++) {
        k=(k*i)%MOD;
    }
    return k;
}

int main(){
    int i,j,k,l,m,n,t,x,y,f;
    long long s;
    int a[200010];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        sort(a,a+n);
        k=a[0];
        f=0;
        for(j=1;j<n;j++) {
            x=a[0];
            y=a[j];
            while(x!=0) {
                if (x%2>y%2) {
                    f=1;
                    break;
                }
                x>>=1;
                y>>=1;
            }
            if (f==1) break;
        }
        if (n==1) {
            cout<<1<<endl;
            continue;
        }
        if (f==1) {
            cout<<0<<endl;
            continue;
        }
        if (a[0]!=a[1]) {
            cout<<0<<endl;
            continue;
        }
        k=2;
        s=0;
        while((k<n)&&(a[k]==a[0])) k++;
        s=(jie(k)*inv(jie(k-2)))%MOD;
        s=(s*jie(n-2))%MOD;
        cout<<s<<endl;
    }
    return 0;
}