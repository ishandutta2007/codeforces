#include <cstdio>
#include <iostream>
using namespace std;

int m,n;
int sr[1024];
int sc[1024];

int abs(int x){
    return (x>=0)?x:(-x);
}

long long fr(int k){
    int i;
    long long r=0;
    for(i=0;i<m;++i){
        long long p=abs(4*k-(4*i+2));
        r+=((long long)sr[i])*p*p;
    }
    return r;
}

long long fc(int k){
    int i;
    long long r=0;
    for(i=0;i<n;++i){
        long long p=abs(4*k-(4*i+2));
        r+=((long long)sc[i])*p*p;
    }
    return r;
}

int main(){
    int i,j;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){
            int k;
            scanf("%d",&k);
            sr[i]+=k;
            sc[j]+=k;
        }
    }
    int ri,rj;
    long long mi,mj;
    ri=0;mi=fr(0);
    for(i=1;i<=m;++i){
        long long k=fr(i);
        if(k<mi){
            ri=i;
            mi=k;
        }
    }

    rj=0;mj=fc(0);
    for(i=1;i<=n;++i){
        long long k=fc(i);
        if(k<mj){
            rj=i;
            mj=k;
        }
    }

    cout<<mi+mj<<endl<<ri<<' '<<rj<<endl;

    return 0;
}