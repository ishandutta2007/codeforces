#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100005;
int n, K, a[N];
void mergeSort(int l, int r, int k){
    if(k <= 0) return ;
    k-=2;
    int mid = (l + r) >> 1;
    int len = mid - l;
    swap(a[mid - 1], a[mid]);
    mergeSort(l, mid, min(k, 2 * (len - 1)));
    mergeSort(mid, r, k - 2 * (len - 1));
}
int main(){
    scanf("%d%d", &n, &K);
    if((K & 1) == 0 || K > 2 * n - 1) { puts("-1"); return 0; }
    for(int i = 0; i < n; i++) 
        a[i] = i + 1;

    mergeSort(0, n, K - 1);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}