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

int N,J,K,A[51],S[51],ans,day;
bool B[500005];
vector <int> V;

int main()
{
    int i,j,k,sum=0;
    scanf("%d%d",&N,&J);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    B[0] = 1;
    for (i=1;i<=N;i++){
        for (j=sum;j>=0;j--) if (B[j]) B[j+A[i]] = 1;
        sum += A[i];
    }
    for (ans=day=0,i=1;;){
        bool sw=0; int t=0;
        for (;i<=min(ans+J,500000);i++) if (B[i]){
            t = i;
            sw = 1;
        }
        if (!sw) break;
        day++; ans = t;
    }
    printf("%d %d\n",ans,day);
}