#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5 + 10;
int n, a[nax];
int go(int v,int l, int r){
    int c = ((a[l] & (1 << v)) == (a[r] & (1 << v))) ? 0 : (1 << v);
    if(l > r) return 0;

    if(v == 0) return c;
    if(c == 0) return go(v - 1, l , r);

    int tar = -1;
    for(int i = l ;i <= r ;i ++){
        if((a[i] & (1 << v))){
            tar = i - 1;
            break;
        }
    }
     if(tar == -1) throw;
    return c + min(go(v - 1, l, tar), go(v - 1, tar + 1, r));
}

int main(){
    scanf("%d", &n);
    for(int i = 1 ;i <= n; i ++){
        scanf("%d", &a[i]);
    }
    sort(a + 1 , a + 1 + n);
    int now = a[n];
    int mxlv = 0;
    for(; now > 0 ; now >>= 1)
        mxlv ++ ;
  //  fprintf(stderr, "mxlv = %d ALIVE\n", mxlv);
    printf("%d\n", go(mxlv, 1, n));
}