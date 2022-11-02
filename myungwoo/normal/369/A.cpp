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

int N,M,K,S,A[1004],X,Y,ans;

int main()
{
    int i,j,k;
    scanf("%d%d%d",&N,&M,&K);
    for (i=1;i<=N;i++){
        scanf("%d",A+i);
        if (A[i] == 1) S++;
    }
    for (i=1;i<=N;i++){
        if (A[i] == 1){
            X++;
            if (X > M) ans++;
        }else if (A[i] == 2){
            if (S < M) S++, X++;
            else{
                Y++;
                if (Y > K) ans++;
            }
        }
    }
    printf("%d\n",ans);
}