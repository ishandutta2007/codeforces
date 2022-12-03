#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    string s;
    int a[1000];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        cin>>s;
        k=0;
        while(k<n&&s[k]=='?') k++;
        if (k==n) {
            for(j=0;j<n;j++) {
                if (j&1) cout<<'B';
                else cout<<'R';
            }
            cout<<endl;
            continue;
        }
        if (s[k]=='B') a[k]=1;
        else a[k]=0;
        for(j=k-1;j>=0;j--) {
            a[j]=1-a[j+1];
        }
        for(j=k;j<n;j++) {
            while(j<n&&s[j]!='?') {
                if (s[j]=='B') a[j]=1;
                else a[j]=0;
                j++;
            }
            while(j<n&&s[j]=='?') {
                a[j]=1-a[j-1];
                j++;
            }
            j--;
        }
        for(j=0;j<n;j++) {
            if (a[j]==1) cout<<'B';
            else cout<<'R';
        }
        cout<<endl;
    }
    return 0;
}