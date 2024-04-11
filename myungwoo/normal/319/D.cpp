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

#define MAXN 50004

int N;
char A[MAXN];

int main()
{
    int i,len;
    scanf("%s",A); N = strlen(A);
    for (len=1;len<=N/2;len++){
        int cnt=0,p=len;
        for (i=len;i<N;i++){
            cnt = (A[i]==A[i-len]?cnt+1:0);
            if (cnt == len){
                p -= len;
                cnt = 0;
            }
            A[p++] = A[i];
        }
        A[N=p] = 0;
    }
    puts(A);
}