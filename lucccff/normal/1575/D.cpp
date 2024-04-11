#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,ans=0,p=10,q=0,s;
    char a[8];
    string s1;
    cin>>s1;
    n=s1.length();
    for(i=0;i<n;i++) {
        a[n-i-1]=s1[i];
    }
    if (a[n-1]=='X') p=9;
    if (n==1) {
        if (a[0]=='X'||a[0]=='_'||a[0]=='0') {
            cout<<1;
        }
        else {
            cout<<0;
        }
        return 0;
    }
    if (n==2) {
        for(i=25;i<=75;i+=25) {
            if (a[0]==i%10+'0'||a[0]=='_') {
                if (a[1]==i/10+'0'||a[1]=='_') {
                    s=1;
                    for(j=2;j<n;j++) {
                        if (a[j]=='X') q=1;
                        if (a[j]=='_') {
                            if (j==n-1) s*=9;
                            else s*=10;
                        }
                    }
                    if (q) s*=p;
                    ans+=s;
                }
                else if (a[1]=='X') {
                    p=1;
                    s=1;
                    for(j=2;j<n;j++) {
                        if (a[j]=='X') q=1;
                        if (a[j]=='_') {
                            if (j==n-1) s*=9;
                            else s*=10;
                        }
                    }
                    if (q) s*=p;
                    ans+=s;
                }
            }
            else if (a[0]=='X') {
                p=1;
                if (a[1]==i/10+'0'||a[1]=='_') {
                    s=1;
                    for(j=2;j<n;j++) {
                        if (a[j]=='X') q=1;
                        if (a[j]=='_') {
                            if (j==n-1) s*=9;
                            else s*=10;
                        }
                    }
                    if (q) s*=p;
                    ans+=s;
                }
            }
        }
    }
    else {
        if (a[n-1]=='0') {
            cout<<0;
            return 0;
        }
        for(i=25;i<=75;i+=25) {
            if (a[0]==i%10+'0'||a[0]=='_') {
                if (a[1]==i/10+'0'||a[1]=='_') {
                    s=1;
                    for(j=2;j<n;j++) {
                        if (a[j]=='X') q=1;
                        if (a[j]=='_') {
                            if (j==n-1) s*=9;
                            else s*=10;
                        }
                    }
                    if (q) s*=p;
                    ans+=s;
                }
                else if (a[1]=='X') {
                    p=1;
                    s=1;
                    for(j=2;j<n;j++) {
                        if (a[j]=='X') q=1;
                        if (a[j]=='_') {
                            if (j==n-1) s*=9;
                            else s*=10;
                        }
                    }
                    if (q) s*=p;
                    ans+=s;
                }
            }
            else if ((a[n-1]!='X'||i!=50)&&a[0]=='X') {
                p=1;
                if (a[1]==i/10+'0'||a[1]=='_') {
                    s=1;
                    for(j=2;j<n;j++) {
                        if (a[j]=='X') q=1;
                        if (a[j]=='_') {
                            if (j==n-1) s*=9;
                            else s*=10;
                        }
                    }
                    if (q) s*=p;
                    ans+=s;
                }
            }
        }
        i=0;
        if (a[n-1]!='X') {
            if (a[0]==i%10+'0'||a[0]=='_') {
                if (a[1]==i/10+'0'||a[1]=='_') {
                    s=1;
                    for(j=2;j<n;j++) {
                        if (a[j]=='X') q=1;
                        if (a[j]=='_') {
                            if (j==n-1) s*=9;
                            else s*=10;
                        }
                    }
                    if (q) s*=p;
                    ans+=s;
                }
                else if (a[1]=='X') {
                    p=1;
                    s=1;
                    for(j=2;j<n;j++) {
                        if (a[j]=='X') q=1;
                        if (a[j]=='_') {
                            if (j==n-1) s*=9;
                            else s*=10;
                        }
                    }
                    if (q) s*=p;
                    ans+=s;
                }
            }
            else if (a[0]=='X') {
                p=1;
                if (a[1]==i/10+'0'||a[1]=='_'||a[1]=='X') {
                    s=1;
                    for(j=2;j<n;j++) {
                        if (a[j]=='X') q=1;
                        if (a[j]=='_') {
                            if (j==n-1) s*=9;
                            else s*=10;
                        }
                    }
                    if (q) s*=p;
                    ans+=s;
                }
            }
        }
        else {
            if (a[0]==i%10+'0'||a[0]=='_') {
                if (a[1]==i/10+'0'||a[1]=='_') {
                    s=1;
                    for(j=2;j<n;j++) {
                        if (a[j]=='X') q=1;
                        if (a[j]=='_') {
                            if (j==n-1) s*=9;
                            else s*=10;
                        }
                    }
                    if (q) s*=p;
                    ans+=s;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}