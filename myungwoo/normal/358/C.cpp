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

#define MAXN 100005

int N,A[MAXN],num[MAXN];
bool chk[MAXN];

int main()
{
    int i,j;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    for (i=1;i<=N;i++) if (!A[i]){
        vector <pii> list;
        for (j=i-1;j>0;j--) if (A[j]){
            list.pb(mp(-A[j],j));
        }else break;
        sort(all(list));
        for (j=0;j<3&&j<sz(list);j++) chk[list[j].sc] = 1;
    }
    int cnt=0,cnt2=0;
    for (i=1;i<=N;i++){
        if (A[i]){
            cnt++;
            if (chk[i]){
                if (cnt2 == 0) puts("pushStack");
                else if (cnt2 == 1) puts("pushQueue");
                else puts("pushFront");
                cnt2++;
            }else{
                puts("pushBack");
            }
        }else{
            printf("%d",cnt2);
            if (cnt2-- > 0) printf(" popStack");
            if (cnt2-- > 0) printf(" popQueue");
            if (cnt2-- > 0) printf(" popFront");
            cnt2 = 0;
            puts("");
        }
    }
}