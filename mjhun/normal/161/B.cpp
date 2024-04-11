#include <algorithm>
#include <cstdio>
#include <iostream>
#define mp make_pair
#define fst first
#define snd second
#define INF 1000000000
using namespace std;

int n,k;
int ns,np;
pair<int,int> s[1024];
bool bs[1024];
pair<int,int> p[1024];
bool bp[1024];
double r;

bool comp(pair<int,int> p1, pair<int,int> p2){
    return p1.fst>p2.fst;
}

int main(){
    int i;int minc=INF;
    scanf("%d %d",&n,&k);
    ns=np=0;
    r=0.;
    for(i=0;i<n;++i){
        int c,t;
        scanf("%d %d",&c,&t);
        if(t==1){
            s[ns++]=mp(c,i);
        }
        else{
            p[np++]=mp(c,i);
        }
        r+=c;
        if(c<minc)minc=c;
    }
    sort(s,s+ns,comp);
    for(i=0;i<min(k-1,ns);++i){
        r-=s[i].fst/2.;
    }
    if(ns>k-1){
        r-=(double)minc/2.;
    }

    printf("%.1lf\n",r);

    for(i=0;i<min(k-1,ns);++i){
        printf("1 %d\n",s[i].snd+1);
    }
    int cp=0;
    for(;i<k-1;++i,++cp){
        printf("1 %d\n",p[cp].snd+1);
    }

    printf("%d",n-(k-1));
    for(i=k-1;i<ns;++i){
        printf(" %d",s[i].snd+1);
    }
    for(;cp<np;++cp){
        printf(" %d",p[cp].snd+1);
    }

    putchar('\n');

    return 0;
}