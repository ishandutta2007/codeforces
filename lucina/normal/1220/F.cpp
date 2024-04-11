#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 2, Log = 19;
int a[maxn],n, pos, b[maxn], lg[maxn];
int sp[Log][maxn];
int Min(int l,int r){
    return a[l] < a[r] ? l : r;
}
void sparse_table(){
    for(int i=2 ;i <=n;i++)
        lg[i] = lg[i >> 1] + 1;
    for(int i=1 ;i <= n;i++)
        sp[0][i] = i;
    for(int j = 1 ; j<Log ;j++){
        for(int i=1 ; i + (1<<(j)) <= n + 1;i++){
            sp[j][i] = Min(sp[j-1][i], sp[j-1][i + (1 << (j-1))]);
        }
    }
    ///ok got bug with sparse table for the first time.
}
int getMin(int l,int r){
    int d = lg[r - l + 1];
    return Min(sp[d][l] , sp[d][r - (1 << d) + 1]);
}
int dep(int l,int r){
    if(l > r) return 0;
    if(l == r) return 1;
    int pos = getMin(l, r);
    //cout << l << r << endl;
    return max(dep(l, pos-1), dep(pos + 1, r)) + 1;
}

int main(){
    scanf("%d",&n);
    if(n == 1)return !printf("1 0");
    for(int i=1 ;i <= n;i++){
    scanf("%d",&a[i]);
    if(a[i] == 1) pos = i;
    }
    int top = 1;
    for(int i = pos ; i <= n ; i++){
        b[top++] = a[i];
    }
    for(int i = 1 ;i < pos ;i++){
        b[top++] = a[i];
    }
    for(int i = 1 ;i <= n;i++)
        a[i] = b[i] /*printf("%d ",a[i])*/;
    //printf("\n");
    sparse_table();
   // cout << sp[1][3] << endl;
   // cout << getMin(3, 4) << endl;
  //  return 0;
 //   return !printf("%d\n",dep(3,4));
    int l = 2 , r = n , mid, ans = -1;
    while(l <= r){
     //   cout << l << ' ' << r << endl;
        mid = l + r >> 1;
        int x = dep(2,mid);

        int y = (mid + 1 > n) ? 10000000:dep(mid + 1 , n);
       // cout << y << endl;
        if(x <= y){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    assert(ans != -1);
    int x = max(dep(2, ans), dep(ans + 1 ,n));
    int y = ans + 1 <= n ? max(dep(2, ans + 1),dep(ans + 2 , n)) : 10000000;
    printf("%d ",min(x,y) + 1);
    if(y < x) ans++;
        ///let's see the cyclic shift
        /// we want something like 1 to x
        ///so x should be the right most element
        /// we need to shift it more x times
    int shift = pos - 1 + ans;
    if(shift >= n) shift -= n;
    printf("%d ",shift);
}
/**

*/