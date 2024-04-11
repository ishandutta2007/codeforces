#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int


const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e9;
const double eps=1e-9;

pair<int,int> operator+(pair<int,int> p1,pair<int,int> p2){
    return mp(p1.x+p2.x,p1.y+p2.y);
}

pair<int,int> up=mp(-1,0),down=mp(1,0),lft=mp(0,-1),rght=mp(0,1),dir[4],ZERO=mp(0,0);
vector<string> t;
int ans=0;

void deep(pair<int,int> v){
    int s=0,i,j;
    pair<int,int> p,a=ZERO;
    For(i,4){
        p=v+dir[i];
        if(t[p.x][p.y]=='.'){
            if(a!=ZERO) return;
            a=p;
        }
    }
    if(a==ZERO) return;
    For(i,4){
        if(a==v+dir[i]){
            switch(i){
            case 0:
                t[v.x][v.y]='v';
                t[a.x][a.y]='^';
                break;
            case 1:
                t[v.x][v.y]='^';
                t[a.x][a.y]='v';
                break;
            case 2:
                t[v.x][v.y]='>';
                t[a.x][a.y]='<';
                break;
            case 3:
                t[v.x][v.y]='<';
                t[a.x][a.y]='>';
            }
            ans+=2;
            break;
        }
    }
    For(i,4){
        v=a+dir[i];
        if(t[v.x][v.y]=='.'){
            deep(v);
        }
    }
}







void solve(int n){
    vector<pair<int,int>> p;
    string s;
    char c[2020];
    int i,j,m,k=0,l;
    bool fnd=true;
    scanf("%d",&m);
    s.assign(m+2,'*');
    t.resize(n+2);
    t[0]=t[n+1]=s;
    gets(c);
    For(i,n){
        gets(c);
        s=c;
        t[i+1]='*'+s+'*';
    }
    dir[0]=up;
    dir[1]=down;
    dir[2]=lft;
    dir[3]=rght;
    FOR(i,1,n+1){
        FOR(j,1,m+1){
            if(t[i][j]=='.'){
                k++;
                p.pb(mp(i,j));
            }
        }
    }
    if(k%2!=0){
        printf("Not unique");
        return;
    }
    For(l,p.size()){
        if(t[p[l].x][p[l].y]=='.'){
            deep(p[l]);
            /*FOR(i,1,n+1){
                FOR(j,1,m+1){
                    printf("%c",t[i][j]);
                }
                printf("\n");
            }
            printf("\n");*/
        }
    }
    if(k!=ans){
        printf("Not unique");
        return;
    }
    FOR(i,1,n+1){
        FOR(j,1,m+1){
            printf("%c",t[i][j]);
        }
        printf("\n");
    }



#ifdef HOME
    printf("\n\nTime in ms: %.0lf\n",clock()/CLOCKS_PER_SEC*1000);
#endif
}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    while(scanf("%d",&n)==1) solve(n);
    /*printf("2000 2000");
    For(a,2000){
        printf("\n");
        For(n,2000){
            if((n+a)%2==0){
                printf(".");
            }
            else{
                printf("*");
            }
        }
    }*/
    return 0;
}