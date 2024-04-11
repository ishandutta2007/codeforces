#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>
using namespace std;
#define ll long long int
const int mod=1e9+7;

int ah[222222], aw[222222], ch[2222222], cw[2222222];

void buildh(int v, int l, int r){
    if(l==r){
        ch[v]=ah[l];
        return;
    }
    int m=(l+r)/2;
    buildh(2*v,l,m);
    buildh(2*v+1,m+1,r);
    ch[v]=max(ch[2*v],ch[2*v+1]);
}

void buildw(int v, int l, int r){
    if(l==r){
        cw[v]=aw[l];
        return;
    }
    int m=(l+r)/2;
    buildw(2*v,l,m);
    buildw(2*v+1,m+1,r);
    cw[v]=max(cw[2*v],cw[2*v+1]);
}

void modifyh(int v, int l, int r, int i, int x){
    if(l==r){
        ah[l]=x;
        ch[v]=x;
        return;
    }
    int m=(l+r)/2;
    if(m>=i) modifyh(2*v,l,m,i,x);
    else modifyh(2*v+1,m+1,r,i,x); 
    ch[v]=max(ch[2*v],ch[2*v+1]);
}

void modifyw(int v, int l, int r, int i, int x){
    if(l==r){
        aw[l]=x;
        cw[v]=x;
        return;
    }
    int m=(l+r)/2;
    if(m>=i) modifyw(2*v,l,m,i,x);
    else modifyw(2*v+1,m+1,r,i,x); 
    cw[v]=max(cw[2*v],cw[2*v+1]);
}

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int i, j, n, h, w, c;
    char m[11], x;
    ll d;
    map<int,int> mph, mpw;
    map<int,int>::iterator it;
    scanf("%d%d%d",&w,&h,&n);
    for(i=0;i<h;i++){
        ah[i]=0;
    }
    ah[h]=h;
    mph[h]=1;
    buildh(1,0,h+1);
    for(i=0;i<w;i++){
        aw[i]=0;
    }
    aw[w]=w;
    mpw[w]=1;
    buildw(1,0,w+1);
    for(i=0;i<n;i++){
        gets(m);
        x=getchar();
        scanf("%d",&j);
        if(x=='H'){
            it=mph.upper_bound(j);
            c=ah[it->first]-it->first+j;
            modifyh(1,0,h+1,it->first,it->first-j);
            modifyh(1,0,h+1,j,c);
            d=((ll)ch[1])*cw[1];
            printf("%I64d\n",d);
            mph[j]=1;
        }
        else{
            it=mpw.upper_bound(j);
            c=aw[it->first]-it->first+j;
            modifyw(1,0,w+1,it->first,it->first-j);
            modifyw(1,0,w+1,j,c);
            d=((ll)ch[1])*cw[1];
            printf("%I64d\n",d);
            mpw[j]=1;
        }
    }



return 0;
}