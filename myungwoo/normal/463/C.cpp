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

int N,A[2000][2000];
lld P[4010],Q[4010],V[2]={-1,-1},Y[2],X[2];

int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,k;
    cin >> N;
    for (i=0;i<N;i++) for (j=0;j<N;j++) cin >> A[i][j];
    for (i=0;i<N;i++) for (j=0;j<N;j++){
        P[i+j] += A[i][j];
        Q[i-j+2000] += A[i][j];
    }
    for (i=0;i<N;i++) for (j=0;j<N;j++){
        lld v = P[i+j]+Q[i-j+2000]-A[i][j];
        int t = (i+j)&1;
        if (V[t] < v) V[t] = v, Y[t] = i+1, X[t] = j+1;
    }
    cout << V[0]+V[1] << endl;
    cout << Y[0] << " " << X[0] << " " << Y[1] << " " << X[1] << endl;
}