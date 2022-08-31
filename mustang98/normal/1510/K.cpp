//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 1000+10, inf = 1000111222;

int a[2*max_n];
int b[2*max_n];

bool is_sorted(int* a,int n)
{
    for (int i=1;i<n;i++){
        if (a[i]<a[i-1]){
            return 0;
        }
    }
    return 1;
}

void do_op_1(int* a,int n)
{
    for (int i=0;i<n;i+=2){
        swap(a[i],a[i+1]);
    }
}

void do_op_2(int* a,int n)
{
    for (int i=0;i<n/2;i++){
        swap(a[i],a[i+n/2]);
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    for (int i=0;i<2*n;i++){
        cin>>a[i];
    }
    int ans=inf;
    for (int j=0;j<2;j++){
        for (int i=0;i<2*n;i++){
            b[i]=a[i];
        }
        for (int iter=0;iter<=30000;iter++){
            if (is_sorted(b,2*n)){
                ans=min(ans,iter);
            }
            if ((iter+j)%2==0){
                do_op_1(b,2*n);
            }
            else{
                do_op_2(b,2*n);
            }
        }
    }
    cout<<(ans==inf ? -1 : ans)<<"\n";
}