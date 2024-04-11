#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#define For(i,n) for(i=0;i<(n);i++)

int c[4][4];

void inc(int x){
    int x1,y1;
    x1=c[x][0];
    y1=c[x][1];
    c[x][0]=c[x][2]+c[x][3]-y1;
    c[x][1]=c[x][3]+x1-c[x][2];
}

int min(int a,int b){
    return a<b?a:b;
}

bool check(){
    int i;
    long long int d[6];
    bool ans=false,t;
    d[0]=(long long int)(c[0][0]-c[1][0])*(c[0][0]-c[1][0])+(long long int)(c[0][1]-c[1][1])*(c[0][1]-c[1][1]);
    d[1]=(long long int)(c[1][0]-c[2][0])*(c[1][0]-c[2][0])+(long long int)(c[1][1]-c[2][1])*(c[1][1]-c[2][1]);
    d[2]=(long long int)(c[2][0]-c[3][0])*(c[2][0]-c[3][0])+(long long int)(c[2][1]-c[3][1])*(c[2][1]-c[3][1]);
    d[3]=(long long int)(c[3][0]-c[0][0])*(c[3][0]-c[0][0])+(long long int)(c[3][1]-c[0][1])*(c[3][1]-c[0][1]);
    d[4]=(long long int)(c[2][0]-c[0][0])*(c[2][0]-c[0][0])+(long long int)(c[2][1]-c[0][1])*(c[2][1]-c[0][1]);
    d[5]=(long long int)(c[1][0]-c[3][0])*(c[1][0]-c[3][0])+(long long int)(c[1][1]-c[3][1])*(c[1][1]-c[3][1]);
    std::sort(d,d+6);
    if(d[0]==d[1]&&d[1]==d[2]&&d[2]==d[3]&&d[4]==d[3]*2&&d[4]==d[5]&&d[0]!=0) return true;
    else return false;
}


void solve(int n){
    int i,j,t,l[4],m=16;
    For(t,n){
        m=16;
        For(i,4){
            For(j,4){
                scanf("%d",&c[i][j]);
            }
        }
        For(l[0],4){
            inc(0);
            For(l[1],4){
                inc(1);
                For(l[2],4){
                    inc(2);
                    For(l[3],4){
                        inc(3);
                        if(check()) m=min(m,(l[0]+1)%4+(l[1]+1)%4+(l[2]+1)%4+(l[3]+1)%4);
                    }
                }
            }
        }
        if(m==16) printf("-1\n");
        else printf("%d\n",m);
    }
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,l;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}