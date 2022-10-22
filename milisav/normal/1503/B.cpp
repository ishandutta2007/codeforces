#include<bits/stdc++.h>
#define maxn 200
using namespace std;
int n;
int m[maxn][maxn];
int ao;
int a;
int bo;
int ba;
int bc=3;
int main() {
    scanf("%d",&n);
    scanf("%d",&ao);
    int mov=n*n-1;
    bo=2;
    ba=1;
    if(ao==2) {
        bo=1;
        ba=2;
    }
    int x=0,y=0;
    bool fn=true;
    while(m[x][y]!=0) {
        y=y+2;
        if(y>=n) {
            x++;
            y=x&1;
            if(x>=n) {
                fn=false;
                break;
            }
        }
    }
    if(fn) {
        printf("%d %d %d\n",bo,x+1,y+1);
        m[x][y]=bo;
        fflush(stdout);
    }
    while(mov>0) {
        scanf("%d",&a);
        mov--;
        if(a!=bo) {
            int x=0,y=0;
            bool fn=true;
            while(m[x][y]!=0) {
                y=y+2;
                if(y>=n) {
                    x++;
                    y=x&1;
                    if(x>=n) {
                        fn=false;
                        break;
                    }
                }
            }
            if(fn) {
                printf("%d %d %d\n",bo,x+1,y+1);
                m[x][y]=bo;
                fflush(stdout);
                continue;
            }
        }
        if(a!=ba) {
            int x=0,y=1;
            bool fn=true;
            while(m[x][y]!=0) {
                y=y+2;
                if(y>=n) {
                    x++;
                    y=1-(x&1);
                    if(x>=n) {
                        fn=false;
                        break;
                    }
                }
            }
            if(fn) {
                printf("%d %d %d\n",ba,x+1,y+1);
                m[x][y]=ba;
                fflush(stdout);
                continue;
            }
        }
        int x=0,y=0;
        bool fn=true;
        while(m[x][y]!=0) {
            y=y+1;
            if(y>=n) {
                x++;
                y=0;
                if(x>=n) {
                    fn=false;
                    break;
                }
            }
        }
        printf("%d %d %d\n",bc,x+1,y+1);
        m[x][y]=bc;
        fflush(stdout);
    }
}