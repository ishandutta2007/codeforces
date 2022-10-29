#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int seq[100005];
int m[100005];
int p[100005];
int n;

int bs(int l, int num){
    int mx=l+1,mn=0,mid;
    while(mx-mn>1){
        mid=(mx+mn)/2;
        if(seq[m[mid]]<num)
            mn=mid;
        else
            mx=mid;
    }
    return mn;
}

int lis(){
    int i,j,l=0,r=0;
    for(i=0;i<n;++i){
        j=bs(l,seq[i]);
        p[i]=m[j];
        if(j==l||seq[i]<seq[m[j+1]]){
            m[j+1]=i;
            l=max(l,j+1);
        }
    }
    j=m[l];
    while(j!=-1){
        r++;
        j=p[j];
    }
    return r;
}

int main(){
    int i;
    memset(m,-1,sizeof(m));
    memset(p,-1,sizeof(p));
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",seq+i);
    }
    printf("%d\n",lis());
    return 0;
}