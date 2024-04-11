#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
    long long i,j,k,l,m,n,t;
    char ch;
    cin>>t;
    getchar();
    for(i=0;i<t;i++) {
        k=0;
        l=0;
        m=0;
        ch=getchar();
        while(ch!='\n'&&ch&&ch!=EOF) {
            if (ch=='0') k=1;
            if (!((int)(ch-'0')&1)) l++;
            m+=ch-'0';
            ch=getchar();
        }
        if (m%3==0&&k==1&&l>1) {
            cout<<"red\n";
        }
        else {
            cout<<"cyan\n";
        }
    }
    return 0;
}