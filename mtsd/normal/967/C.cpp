#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <iomanip>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    int n,m,l,e,v;
    scanf("%d %d %d %d %d",&n,&m,&l,&e,&v);
    vector<int> a(l),b(e),ac(l),bc(e);
    rep(i,l)scanf("%d",&a[i]);
    rep(i,e)scanf("%d",&b[i]);
    rep(i,l)ac[i] = -a[l-i-1];
    rep(i,e)bc[i] = -b[e-i-1];
    int q;
    scanf("%d",&q);
    rep(t,q){ 
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
        if(x1>x2){
            swap(x1,x2);
            swap(y1,y2);
        }
        if(l==0){
            int ans = inf;
            int p2 = -1;
            int q2 = -1;
            if(lower_bound(b.begin(),b.end(),x1)!=b.end()){
                p2 = *lower_bound(b.begin(),b.end(),x1);
            }
            if(lower_bound(bc.begin(),bc.end(),-x2)!=bc.end()){
                q2 = -*lower_bound(bc.begin(),bc.end(),-x2);
            }
            if(p2>=x1&&p2<=x2){
                ans = (abs(y1-y2)+v-1)/v + x2-x1;
                printf("%d\n",ans);
            }else{
                int tmp1 = inf;
                int tmp2 = inf;
                if(p2!=-1){
                    tmp1 = (abs(y1-y2)+v-1)/v + x2-x1 + 2*(p2-x2);
                }
                if(q2!=-1){
                    tmp2 = (abs(y1-y2)+v-1)/v + x2-x1 + 2*(x1-q2);
                }
                ans = min(tmp1,tmp2);
                if(y1==y2){
                    ans = abs(x1-x2);
                }
                printf("%d\n",ans);
            }
        }else if(e==0){
            int ans = inf;
            int p1 = -1;
            int q1 = -1;
            if(lower_bound(a.begin(),a.end(),x1)!=a.end()){
                p1 = *lower_bound(a.begin(),a.end(),x1);
            }
            if(lower_bound(ac.begin(),ac.end(),-x2)!=ac.end()){
                q1 = -*lower_bound(ac.begin(),ac.end(),-x2);
            }
            if(p1>=x1&&p1<=x2){
                ans = abs(y1-y2) + x2-x1;
                printf("%d\n",ans);
            }else{
                int tmp1 = inf;
                int tmp2 = inf;
                if(p1!=-1){
                    tmp1 = abs(y1-y2) + x2-x1 + 2*(p1-x2);
                }
                if(q1!=-1){
                    tmp2 = abs(y1-y2) + x2-x1 + 2*(x1-q1);
                }
                ans = min(tmp1,tmp2);
                if(y1==y2){
                    ans = abs(x1-x2);
                }
                printf("%d\n",ans);
            }
        }else{
            int ans = inf;
            int p1 = -1;
            int q1 = -1;
            if(lower_bound(a.begin(),a.end(),x1)!=a.end()){
                p1 = *lower_bound(a.begin(),a.end(),x1);
            }
            if(lower_bound(ac.begin(),ac.end(),-x2)!=ac.end()){
                q1 = -*lower_bound(ac.begin(),ac.end(),-x2);
            }
            if(p1>=x1&&p1<=x2){
                ans = min(ans,abs(y1-y2) + x2-x1);
            }else{
                int tmp1 = inf;
                int tmp2 = inf;
                if(p1!=-1){
                    tmp1 = abs(y1-y2) + x2-x1 + 2*(p1-x2);
                }
                if(q1!=-1){
                    tmp2 = abs(y1-y2) + x2-x1 + 2*(x1-q1);
                }
                ans = min(ans,min(tmp1,tmp2));
            }

            int p2 = -1;
            int q2 = -1;
            if(lower_bound(b.begin(),b.end(),x1)!=b.end()){
                p2 = *lower_bound(b.begin(),b.end(),x1);
            }
            if(lower_bound(bc.begin(),bc.end(),-x2)!=bc.end()){
                q2 = -*lower_bound(bc.begin(),bc.end(),-x2);
            }
            if(p2>=x1&&p2<=x2){
                ans = min(ans,(abs(y1-y2)+v-1)/v + x2-x1);
            }else{
                int tmp1 = inf;
                int tmp2 = inf;
                if(p2!=-1){
                    tmp1 = (abs(y1-y2)+v-1)/v + x2-x1 + 2*(p2-x2);
                }
                if(q2!=-1){
                    tmp2 = (abs(y1-y2)+v-1)/v + x2-x1 + 2*(x1-q2);
                }
                ans = min(ans,min(tmp1,tmp2));
            }
            if(y1==y2){
                ans = abs(x1-x2);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}