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

const int MOD = 1e9+7;
string S;
int N,M,V[10],L[10];
vector < pair <int,string> > A;

int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,k;
    cin >> S >> M; N = sz(S);
    for (i=0;i<M;i++){
        string s;
        cin >> s;
        int d = s[0]-'0';
        s = s.substr(3);
        A.pb(mp(d,s));
    }
    reverse(all(A));
    for (i=0;i<10;i++) V[i] = i, L[i] = 10;
    for (auto p: A){
        int d = p.first;
        int len = 1, v = 0;
        for (char c: p.second){
            v = ((lld)v*L[c-'0'] + V[c-'0'])%MOD;
            len = (lld)len*L[c-'0']%MOD;
        }
        L[d] = len; V[d] = v;
    }
    int ans = 0;
    for (char c: S){
        ans = ((lld)ans*L[c-'0'] + V[c-'0'])%MOD;
    }
    cout << ans << endl;
}