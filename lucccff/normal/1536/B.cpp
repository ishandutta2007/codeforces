#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t;
    long long a[26],b[26][26],c[26][26][26];
    char ch[1010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(j=0;j<n;j++) {
            cin>>ch[j];
        }
        for(j=0;j<n;j++) {
            a[ch[j]-'a']++;
        }
        k=0;
        for(j=0;j<26;j++) {
            if (a[j]==0) {
                k=1;
                cout<<char(j+'a')<<endl;
                break;
            }
        }
        if (k==1){
            continue;
        }
        for(j=0;j<n-1;j++) {
            b[ch[j]-'a'][ch[j+1]-'a']++;
        }
        for(j=0;j<26;j++) {
            for(l=0;l<26;l++) {
                if (b[j][l]==0) {
                    k=1;
                    cout<<char(j+'a')<<char(l+'a')<<endl;
                    break;
                }
            }
            if (k==1) {
                break;
            }
        }
        if (k==1) {
            continue;
        }
        for(j=0;j<n-2;j++) {
            c[ch[j]-'a'][ch[j+1]-'a'][ch[j+2]-'a']++;
        }
        for(j=0;j<26;j++) {
            for(l=0;l<26;l++) {
                for(m=0;m<26;m++) {
                    if (c[j][l][m]==0) {
                        k=1;
                        cout<<char(j+'a')<<char(l+'a')<<char(m+'a')<<endl;
                        break;
                    }
                }
                if (k==1) {
                    break;
                }
            }
            if (k==1) {
                break;
            }
        }
        if (k==1) {
            continue;
        }
    }
    return 0;
}