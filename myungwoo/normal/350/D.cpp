#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#pragma comment(linker,"/STACK:33554432")

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+value)%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef pair<int,int> pii;
typedef long long lld;

int N,M; lld ans;
int X[1501],Y[1501],R[1501];

lld gcd(lld a,lld b){ return b?gcd(b,a%b):a; }

struct LINE{
    LINE(){}
    LINE(lld ap,lld aq,lld bp,lld bq): ap(ap), aq(aq), bp(bp), bq(bq) {}
    void correct(){
        if (aq < 0) ap *= -1, aq *= -1;
        if (bq < 0) bp *= -1, bq *= -1;
        lld g=gcd(abs(ap),aq);
        ap /= g, aq /= g;
        g = gcd(abs(bp),bq);
        bp /= g, bq /= g;
    }
    lld ap,aq,bp,bq;
    bool operator < (const LINE &ot)const{
        if (ap != ot.ap) return ap < ot.ap;
        if (aq != ot.aq) return aq < ot.aq;
        if (bp != ot.bp) return bp < ot.bp;
        if (bq != ot.bq) return bq < ot.bq;
        return 0;
    }
};

LINE make_line(lld ax,lld ay,lld bx,lld by)
{
    if (bx != ax && by != ay){
        LINE ret((by-ay),(bx-ax),-(by-ay)*ax+(bx-ax)*ay,bx-ax);
        ret.correct();
        return ret;
    }else if (ax == bx){
        LINE ret(1,0,ax,1);
        return ret;
    }else if (ay == by){
        LINE ret(-1,0,ay,1);
        return ret;
    }
}

map < LINE,vector<lld> > S,E;
map < LINE,vector<lld> >::iterator it;

int main()
{
    int i,j,k;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++){
        int ax,ay,bx,by;
        scanf("%d%d%d%d",&ax,&ay,&bx,&by); ax <<= 1, ay <<= 1, bx <<= 1, by <<= 1;
        LINE line = make_line(ax,ay,bx,by);
        E[line].pb(ax==bx?max(ay,by):max(ax,bx));
        S[line].pb(ax==bx?min(ay,by):min(ax,bx));
    }
    for (it=S.begin();it!=S.end();++it) sort(all(it->second));
    for (it=E.begin();it!=E.end();++it) sort(all(it->second));
    for (i=1;i<=M;i++) scanf("%d%d%d",X+i,Y+i,R+i), X[i] <<= 1, Y[i] <<= 1, R[i] <<= 1;
    for (i=1;i<M;i++) for (j=i+1;j<=M;j++) if (R[i] == R[j]){
        if ((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]) <= 4*R[i]*R[i]) continue;
        LINE line = make_line(X[i],Y[i],X[j],Y[j]);
        line.ap *= -1;
        line.correct();
        if (X[i] == X[j]){
            line.bp = (Y[i]+Y[j])>>1; line.bq = 1;
        }else if (Y[i] == Y[j]){
            line.bp = (X[i]+X[j])>>1, line.bq = 1;
        }else{
            swap(line.ap,line.aq); line.correct();
            int y = (Y[i]+Y[j])>>1, x = (X[i]+X[j])>>1;
            line.bp = line.aq*y-line.ap*x;
            line.bq = line.aq;
        }
        line.correct();
        if (!S.count(line)) continue;
        vector <lld> &s = S[line], &e = E[line];
        lld t = 0;
        if (X[i] == X[j]){
            t = X[i];
        }else if (Y[i] == Y[j]){
            t = Y[i];
        }else{
            t = (X[i]+X[j])>>1;
        }
        int cnt=(e.end()-lower_bound(all(e),t))-(s.end()-upper_bound(all(s),t));
        ans += cnt;
    }
    printf("%lld\n",ans);
}