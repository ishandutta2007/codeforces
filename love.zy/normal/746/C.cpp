#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
  
const int maxn = 1010;
int s,x1,x2,t1,t2,p,d;
int man,train;
void shuru(){
    scanf("%d%d%d",&s,&x1,&x2);
    scanf("%d%d",&t1,&t2);
    scanf("%d%d",&p,&d);
}

void gogogo(){
    int  t = 0;
    man = t2*max((x1-x2),(x2-x1));
    if(d == 1){
        if(x1<x2){
             if(p<=x1){
                 t = x2-p;
            }
             else{
                 t = 2*s+x2-p;
            }
        }
       else{
        t = 2*s-p-x2;
       }
    }
    if(d == -1){
        if(x1<x2){
            t = p+x2;
        }
        else if(p>=x1){
            t = p-x2;
        }
        else{
            t = 2*s+p-x2;
        }
    }
    t = t*t1;
    printf("%d\n",min(man,t));
}

int main(){
    shuru();
    gogogo();
    return 0;
}