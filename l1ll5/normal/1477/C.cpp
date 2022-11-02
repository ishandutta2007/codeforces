#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 5005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
struct point{
    int x,y;
    friend point operator - (const point &a,const point &b) {
        return (point){a.x-b.x,a.y-b.y};
    }
}p[N];
ll dot(point a,point b) {
    return 1ll*a.x*b.x + 1ll*a.y*b.y;
}
int a[N];
bool check(){
    for(int i=3;i<=n;i++) {
        point v1 = p[ a[ i - 2 ] ] - p[ a[ i - 1 ] ];
        point v2 = p[ a[ i - 1 ] ] - p[ a[ i - 0 ] ];
        if(dot(v1,v2)>=0) return 0;
    }
    return 1;
}
int main()
{
    srand(time(0));
    n=read();
    for(int i=1;i<=n;i++) p[i].x=read(),p[i].y=read();
    for(int i=1;i<=n;i++) a[i]=i;
    for(int i=1;i<=n;i++) swap(a[i], a[rand()%n+1]);

    for(int r = 1 ; r <= 11000; r++) {
        for(int i=3;i<=n;i++) {
            point v1 = p[ a[ i - 2 ] ] - p[ a[ i - 1 ] ];
            point v2 = p[ a[ i - 1 ] ] - p[ a[ i - 0 ] ];
        //cerr<<a[i-2]<<' '<<a[i-1]<<' '<<a[i]<<' '<<dot(v1,v2)<<endl;
            if(dot(v1,v2) >= 0 ) {
                swap(a[i-1],a[i]);
            }
        }
    }
    if(check()==0) puts("-1");
    else {
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
    }
}