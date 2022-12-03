#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[100010],b[100010];
char c[100010],ch;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m=0,n,t;
    cin>>n>>t;
    cin>>c;
    for(i=0;i<n;i++) {
        if (c[i]=='a'&&c[i+1]=='b'&&c[i+2]=='c') {
            m++;
        }
    }
    for(i=0;i<t;i++) {
        cin>>k>>ch;
        k--;
        if (c[k]=='a'&&c[k+1]=='b'&&c[k+2]=='c') {
            m--;
        }
        if (k>0&&c[k-1]=='a'&&c[k]=='b'&&c[k+1]=='c') {
            m--;
        }
        if (k>1&&c[k-2]=='a'&&c[k-1]=='b'&&c[k]=='c') {
            m--;
        }
        c[k]=ch;
        if (c[k]=='a'&&c[k+1]=='b'&&c[k+2]=='c') {
            m++;
        }
        if (k>0&&c[k-1]=='a'&&c[k]=='b'&&c[k+1]=='c') {
            m++;
        }
        if (k>1&&c[k-2]=='a'&&c[k-1]=='b'&&c[k]=='c') {
            m++;
        }
        cout<<m<<endl;
    }
    return 0;
}