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
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

int N,P;
string S;

int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,k;
    cin >> N >> P >> S;
    for (i=sz(S);i--;){
        for (j=S[i]-'a'+1;j<P;j++){
            if (i > 0 && S[i-1]-'a' == j || i > 1 && S[i-2]-'a' == j) continue;
            break;
        }
        if (j == P) continue;
        S[i] = j+'a';
        break;
    }
    if (i < 0){ puts("NO"); return 0; }
    for (i++;i<sz(S);i++){
        for (j=0;j<P;j++){
            if (i > 0 && S[i-1]-'a' == j || i > 1 && S[i-2]-'a' == j) continue;
            S[i] = j+'a';
            break;
        }
    }
    cout << S << endl;
}