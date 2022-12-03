#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t,a,b,c,d;
    cin>>a>>b>>c>>d;
    if (c+d!=0&&a>b) {
        cout<<"NO";
        return 0;
    }
    if (a+b!=0&&d>c) {
        cout<<"NO";
        return 0;
    }
    if (a>b+1) {
        cout<<"NO";
        return 0;
    }
    if (d>c+1) {
        cout<<"NO";
        return 0;
    }
    if (abs(a+c-b-d)>1) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    if (b==0) {
        if (a!=0) {
            cout<<0;
        }
        else if (c<d) {
            for(i=0;i<c;i++) {
                cout<<3<<' '<<2<<' ';
            }
            cout<<3;
        }
        else if (c==d) {
            for(i=0;i<c;i++) {
                cout<<3<<' '<<2<<' ';
            }
        }
        else {
            for(i=0;i<d;i++) {
                cout<<2<<' '<<3<<' ';
            }
            cout<<2;
        }
        return 0;
    }
    if (c==0) {
        if (d!=0) {
            cout<<3;
        }
        else if (b<a) {
            for(i=0;i<b;i++) {
                cout<<0<<' '<<1<<' ';
            }
            cout<<0;
        }
        else if (a==b) {
            for(i=0;i<a;i++) {
                cout<<0<<' '<<1<<' ';
            }
        }
        else {
            for(i=0;i<a;i++) {
                cout<<1<<' '<<0<<' ';
            }
            cout<<1;
        }
        return 0;
    }
    if (a+c>b+d) {
        for(i=0;i<a;i++) {
            cout<<0<<' '<<1<<' ';
        }
        for(i=a;i<b;i++) {
            cout<<2<<' '<<1<<' ';
        }
        for(i=0;i<d;i++) {
            cout<<2<<' '<<3<<' ';
        }
        if (c==0) cout<<0;
        else cout<<2;
    }
    else if (a+c==b+d) {
        for(i=0;i<a;i++) {
            cout<<0<<' '<<1<<' ';
        }
        for(i=a;i<b;i++) {
            cout<<2<<' '<<1<<' ';
        }
        for(i=0;i<d;i++) {
            cout<<2<<' '<<3<<' ';
        }
    }
    else {
        for(i=0;i<a;i++) {
            cout<<1<<' '<<0<<' ';
        }
        if (b<=a+c) for(i=a;i<b;i++) {
            cout<<1<<' '<<2<<' ';
        }
        else for(i=a;i<b-1;i++) {
            cout<<1<<' '<<2<<' ';
        }
        for(i=0;i<d-1;i++) {
            cout<<3<<' '<<2<<' ';
        }
        if (d==0) cout<<1;
        else cout<<3;
    }
    return 0;
}