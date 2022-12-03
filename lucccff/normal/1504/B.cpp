#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,x1,x2,y1,y2;
    string s1,s2;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        cin>>s1>>s2;
        k=n/2;
        if (k*2!=n) {
            if (s1[n-1]!=s2[n-1]) {
                cout<<"NO\n";
                continue;
            }
        }
        m=0;
        x1=0;
        y1=0;
        for(j=0;j<k;j++) {
            if (s1[j*2]=='0') x1++;
            if (s1[j*2+1]=='0') x1++;
            if (x1==j+1) {
                int f=0;
                for(int p=y1;p<x1;p++) {
                    if (s1[p*2]!=s2[p*2]) {
                        f=1;
                        break;
                    }
                    if (s1[p*2+1]!=s2[p*2+1]) {
                        f=1;
                        break;
                    }
                }
                if (f==1) {
                    f=0;
                    for(int p=y1;p<x1;p++) {
                        if (s1[p*2]==s2[p*2]) {
                            f=1;
                            break;
                        }
                        if (s1[p*2+1]==s2[p*2+1]) {
                            f=1;
                            break;
                        }
                    }
                }
                if (f==1) {
                    m=1;
                    break;
                }
                y1=x1;
            }
        }
        for(j=y1;j<k;j++) {
            if (s1[j*2]!=s2[j*2]) m=1;
            if (s1[j*2+1]!=s2[j*2+1]) m=1;
        }
        if (m==0) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
    }
    return 0;
}