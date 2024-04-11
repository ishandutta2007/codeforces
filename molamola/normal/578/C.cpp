#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

int n;
int A[200020];
double d[200020];

double get_h(double x){
    d[0] = 0;
    for(int i=1;i<=n;i++){
        d[i] = max(A[i] - x, d[i-1] + A[i] - x);
    }
    return *max_element(d+1, d+1+n);
}

double get_l(double x){
    d[0] = 0;
    for(int i=1;i<=n;i++){
        d[i] = min(A[i] - x, d[i-1] + A[i] - x);
    }
    return *min_element(d+1, d+1+n);
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",A+i);
    double low = *min_element(A+1, A+1+n);
    double high = *max_element(A+1, A+1+n);
    double mid;
    double ans = 0;
    while(high - low > 1e-9){
        mid = (low + high) / 2.0;
        double L = -get_l(mid), H = get_h(mid);
//      printf("%lf %lf %lf\n", mid, L, H);
        if(H > L)low = mid, ans = L;
        else high = mid, ans = H;
    }
    printf("%lf",ans);
    return 0;
}