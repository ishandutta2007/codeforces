#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    int a[200010],b[2],c[100010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        b[0]=b[1]=0;
        for(j=0;j<n;j++) {
            cin>>a[j];
            b[a[j]&1]++;
        }
        if (abs(b[0]-b[1])>1) {
            cout<<-1<<endl;
            continue;
        }
        if (n&1) {
            if (b[0]>b[1]) {
                k=0;
                l=0;
                for(j=0;j<n;j++) {
                    if (a[j]&1) {
                        l+=abs(2*k+1-j);
                        k++;
                    }
                }
                cout<<l<<endl;
            }
            else {
                k=0;
                l=0;
                for(j=0;j<n;j++) {
                    if ((a[j]&1)==0) {
                        l+=abs(2*k+1-j);
                        k++;
                    }
                }
                cout<<l<<endl;
            }
        }
        else {
            k=0;
            l=0;
            for(j=0;j<n;j++) {
                if (a[j]&1) {
                    l+=abs(2*k+1-j);
                    k++;
                }
            }
            k=0;
            m=0;
            for(j=0;j<n;j++) {
                if ((a[j]&1)==0) {
                    m+=abs(2*k+1-j);
                    k++;
                }
            }
            cout<<min(l,m)<<endl;
        }
    }
    return 0;
}