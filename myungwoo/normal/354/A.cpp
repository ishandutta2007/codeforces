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
typedef long long lld;
typedef pair<int,int> pii;

#define MAXN 100005

int N,L,R,QL,QR; lld ans=1e17;
int A[MAXN],S[MAXN];

int main()
{
    int i;
    scanf("%d%d%d%d%d",&N,&L,&R,&QL,&QR);
    for (i=1;i<=N;i++) scanf("%d",A+i), S[i] = S[i-1]+A[i];
    for (i=0;i<=N;i++){
        int l=i,r=N-i;
        lld now = S[i]*(lld)L+(S[N]-S[i])*(lld)R;
        if (l < r) now += (lld)QR*(r-l-1);
        if (l > r) now += (lld)QL*(l-r-1);
        put_min(ans,now);
    }
    printf("%lld\n",ans);
}