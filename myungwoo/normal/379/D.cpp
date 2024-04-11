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

int K,X,N,M;
lld D[99]; int C[99];

inline int bits(int n){
    int ret=0;
    for (;n;n>>=1) ret += n&1;
    return ret;
}

inline string make(int len,int cnt,int code)
{
    string ret="";
    if (code&1) ret.pb('C'), len--;
    while (cnt--) ret.pb('A'), ret.pb('C'), len -= 2;
    if (code&2) len--;
    while (len--) ret.pb('B');
    if (code&2) ret.pb('A');
    return ret;
}

int main()
{
    int i,j,k,l,p;
    cin >> K >> X >> N >> M;
    for (i=0;i<=N/2;i++) for (j=0;j<4;j++){
        if (i+i+bits(j) > N) continue;
        for (k=0;k<=M/2;k++) for (l=0;l<4;l++){
            if (k+k+bits(l) > M) continue;
            D[1] = i, C[1] = j;
            D[2] = k, C[2] = l;
            for (p=3;p<=K;p++){
                D[p] = D[p-2]+D[p-1]+((C[p-2]&2)&&(C[p-1]&1));
                if (D[p] > X) break;
                C[p] = (C[p-2]&1)|(C[p-1]&2);
            }
            if (p > K && D[K] == X){
                cout << make(N,i,j) << endl << make(M,k,l) << endl;
                return 0;
            }
        }
    }
    puts("Happy new year!");
}