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
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

int A,B,C,D;
string ans;

int main()
{
    int i;
    cin >> A >> B >> C >> D;
    if (abs(C-D) > 1){ puts("-1"); return 0; }
    if (C > D){ // 4747
        if (A < C || B < C){ puts("-1"); return 0; }
        for (i=0;i<A-C+1;i++) ans.pb('4');
        for (i=1;i<C;i++) ans.pb('7'), ans.pb('4');
        for (i=0;i<B-C+1;i++) ans.pb('7');
    }else if (C < D){ // 7474
        if (A < D || B < D){ puts("-1"); return 0; }
        ans.pb('7');
        for (i=0;i<A-D;i++) ans.pb('4');
        for (i=1;i<D;i++) ans.pb('4'), ans.pb('7');
        for (i=0;i<B-D;i++) ans.pb('7');
        ans.pb('4');
    }else{ // 47474 or 74747
        if (min(A,B) < C || max(A,B) <= C){ puts("-1"); return 0; }
        if (A == C){ // 74747
            ans.pb('7');
            for (i=0;i<C;i++) ans.pb('4'), ans.pb('7');
            for (i=0;i<B-C-1;i++) ans.pb('7');
        }else{ // 47474
            for (i=0;i<A-C;i++) ans.pb('4');
            for (i=1;i<C;i++) ans.pb('7'), ans.pb('4');
            for (i=0;i<B-C+1;i++) ans.pb('7');
            ans.pb('4');
        }
    }
    cout << ans << endl;
}