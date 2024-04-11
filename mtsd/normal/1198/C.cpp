#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int t;
    scanf("%d",&t);
    rep(zz,t){
        int n,m;
        scanf("%d %d",&n,&m);
        vector<bool> flag(3*n+1);
        vector<int > p;
        rep(xx,m){
            int a,b;
            scanf("%d %d",&a,&b);
            if(p.size()==n){
                continue;        
            }
            if(!flag[a]&&!flag[b]){
                flag[a] = 1;
                flag[b] = 1;
                p.push_back(xx+1); 
            }
        }
        if(p.size()==n){
            printf("Matching\n");
            rep(i,n){
                printf("%d",p[i]);
                if(i!=n-1)printf(" ");
            }
            printf("\n");
        }else{
            printf("IndSet\n");
            int c = 0;
            for(int i=1;i<=3*n;i++){
                if(!flag[i]){
                    printf("%d",i);
                    c++;
                    if(c!=n){
                        printf(" ");
                    }
                }
                if(c==n)break;
            }
            printf("\n");
        }

    }



    return 0;
}