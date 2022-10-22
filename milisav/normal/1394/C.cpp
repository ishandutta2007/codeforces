#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 4000000
using namespace std;
int n;
char s[maxn];
int x[maxn];
int y[maxn];
char t[maxn];
int ax,ay,bx,by,az,bz;
pair<int,int> pick_point() {
    if(bx-by>=az && bx-by<=bz) return {bx,by};
    if(bx-by<az) {
        by=bx-az;
        if(by<ay || by<0 || (bx==0 && by==0)) return {-1,-1};
        else return {bx,by};
    }
    if(bx-by>bz) {
        bx=by+bz;
        if(bx<ax || bx<0 || (bx==0 && by==0)) return {-1,-1};
        else return {bx,by};
    }
    return {-1,-1};
}
bool pos(int m) {
    ax=x[0]-m,ay=y[0]-m,bx=x[0]+m,by=y[0]+m,az=x[0]-y[0]-m,bz=x[0]-y[0]+m;
    for(int i=1;i<n;i++) {
        ax=max(ax,x[i]-m);
        bx=min(bx,x[i]+m);
        ay=max(ay,y[i]-m);
        by=min(by,y[i]+m);
        az=max(az,x[i]-y[i]-m);
        bz=min(bz,x[i]-y[i]+m);
    }
    //cout<<m<<" "<<ax<<" "<<ay<<" "<<az<<" "<<bx<<" "<<by<<" "<<bz<<" "<<pick_point().first<<" "<<pick_point().second<<endl;
    if(bx<ax || by<ay || bz<az || bx+by<=0 || by<0 || bx<0 || pick_point().first<0 || pick_point().second<0) return false;
    return true;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%s",s);
        int m=strlen(s);
        for(int j=0;j<m;j++) {
            if(s[j]=='B') x[i]++;
            else y[i]++;
        }
    }
    int l=0;
    int r=maxn;
    while(l<r) {
        int m=(l+r)>>1;
        if(pos(m)) r=m;
        else l=m+1;
    }
    printf("%d\n",l);
    pos(l);
    bx=pick_point().first;
    by=pick_point().second;
    for(int i=0;i<bx;i++) t[i]='B';
    for(int j=0;j<by;j++) t[bx+j]='N';
    t[bx+by]=0;
    printf("%s",t);
	return 0;
}