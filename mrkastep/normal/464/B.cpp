#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#define For(i,n) for(i=0;i<n;i++)

int c[3][8];
long long int cube[30];
bool g=false;

void chk(int p){
    int t=0,a,b,d,i,j;
    if(!g){
        if(p==8){
            For(i,7){
                for(j=i+1;j<8;j++){
                    cube[t]=((long long int)c[0][i]-c[0][j])*((long long int)c[0][i]-c[0][j])+((long long int)c[1][i]-c[1][j])*((long long int)c[1][i]-c[1][j])+((long long int)c[2][i]-c[2][j])*((long long int)c[2][i]-c[2][j]);
                    t++;
                }
            }
            std::sort(cube,cube+28);
            for(i=1;i<12;i++){
                if(cube[i]!=cube[i-1]||cube[i]==0) return;
            }
            if(cube[12]!=cube[0]*2) return;
            for(i=13;i<24;i++){
                if(cube[i]!=cube[i-1]) return;
            }
            if(cube[24]!=cube[0]*3) return;
            for(i=25;i<28;i++){
                if(cube[i]!=cube[i-1]) return;
            }
            if(!g){
                printf("YES\n");
                For(i,8){
                    printf("%d %d %d\n",c[0][i],c[1][i],c[2][i]);
                }
            }
            g=true;
        }
        else{
            a=c[0][p];
            b=c[1][p];
            d=c[2][p];
            chk(p+1);
            c[0][p]=b;
            c[1][p]=a;
            c[2][p]=d;
            chk(p+1);
            c[0][p]=b;
            c[1][p]=d;
            c[2][p]=a;
            chk(p+1);
            c[0][p]=d;
            c[1][p]=b;
            c[2][p]=a;
            chk(p+1);
            c[0][p]=d;
            c[1][p]=a;
            c[2][p]=b;
            chk(p+1);
            c[0][p]=a;
            c[1][p]=d;
            c[2][p]=b;
            chk(p+1);
        }
    }
}

void solve(){
    int i,x[2][3];
    For(i,8){
        scanf("%d%d%d",&c[0][i],&c[1][i],&c[2][i]);
    }
    x[0][0]=c[0][0];
    x[0][1]=c[1][0];
    x[0][2]=c[2][0];
    x[1][0]=c[0][1];
    x[1][1]=c[1][1];
    x[1][2]=c[2][1];
    chk(1);
    if(!g) printf("NO");
}

int main() {
#pragma comment(linker, "/STACK:67108864")
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
int n,m,k;
//while(scanf("%d",&n)!=EOF){
solve();
//}
return 0;
}