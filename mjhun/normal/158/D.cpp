#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


vector<int> p;
vector<int> f;
vector<int> div;

int t[20000];
int n;


void gendiv(int k){
    if(k>=p.size()){
        return;
    }
    gendiv(k+1);
    int i,j,q=1,m=div.size();
    for(j=0;j<f[k];++j){
        q*=p[k];
        for(i=0;i<m;++i){
            div.push_back(q*div[i]);
        }
    }
}

void fact(int m){
    int i=2;
    while(i*i<=m){
        if(m%i==0){
            int q=0;
            while(m%i==0){
                m/=i;
                q++;
            }
            p.push_back(i);
            f.push_back(q);
        }
        i++;
    }
    if(m!=1){
        p.push_back(m);
        f.push_back(1);
    }

    div.push_back(1);
    gendiv(0);
}

//
int main(){
    int i,j,k,r=0;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",t+i);
        r+=t[i];
    }
    fact(n);
    for(i=0;i<div.size();++i){
        int d=div[i];
        if(d==1||d==n||(n%2==0&&d==n/2))continue;
        for(k=0;k<d;++k){
            int s=0;
            for(j=k;j<n;j+=d){
                s+=t[j];
            }
            r=max(r,s);
        }
    }
    printf("%d\n",r);
    return 0;
}