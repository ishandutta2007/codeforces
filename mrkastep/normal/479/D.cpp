#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)

void solve(int n){
    int i,l,x,y,t,ans=2,s=1,m,c,ans1,ans2;
    map<int,int> a;
    map<int,int>::iterator it;
    scanf("%d%d%d",&l,&x,&y);
    For(i,n){
        scanf("%d",&t);
        a[t]=1;
    }
    if(x<y){
        m=x;
        x=y;
        y=m;
    }
    int x1=1,y1=1;
    for(it=a.begin();it->first<=l;it++){
        if(it->second==1){
            if(a[it->first+x]==1){
                ans-=x1;
                x1=0;
            }
            if(a[it->first+y]==1){
                ans-=y1;
                y1=0;
            }
        }
    }
    if(x1==0||y1==0){
        if(x1==0&&y1==0){
            printf("0\n");
            return;
        }
        printf("1\n");
        if(x1==0){
            printf("%d\n",y);
        }
        else printf("%d\n",x);
        return;
    }
    for(it=a.begin();it->first<=l;it++){
        if(it->second==1){
            if(it->first+x<=l&&(a[it->first+x-y]==1||a[it->first+x+y]==1)){
                ans-=s;
                s=0;
                ans1=it->first+x;
            }
        }
    }
    if(ans==2){
        for(it=a.begin();it->first<=l;it++){
            if(it->second==1){
                if(it->first+y<=l&&(a[it->first+y-x]==1||a[it->first+x+y]==1)){
                    ans-=s;
                    s=0;
                    ans1=it->first+y;
                }
            }
        }
    }
    if(ans==2){
        for(it=a.begin();it->first<=l;it++){
            if(it->second==1){
                if(it->first-x>=0l&&(a[it->first-x+y]==1||a[it->first-x-y]==1)){
                    ans-=s;
                    s=0;
                    ans1=it->first-x;
                }
            }
        }
    }
    if(ans==2){
        for(it=a.begin();it->first<=l;it++){
            if(it->second==1){
                if(it->first-y>=0l&&(a[it->first-y-x]==1||a[it->first+x-y]==1)){
                    ans-=s;
                    s=0;
                    ans1=it->first-y;
                }
            }
        }
    }
    printf("%d\n",ans);
    if(ans==1){
        printf("%d\n",ans1);
        return;
    }
    printf("%d %d\n",x,y);
}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}