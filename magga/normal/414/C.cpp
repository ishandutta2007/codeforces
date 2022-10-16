#include<bits/stdc++.h>
using namespace std;
void pre(){}
map<long long int,long long int>re[2];
int oo = 0;
long long int _mergeSort(int arr[], int temp[], int left, int right); 
long long int merge(int arr[], int temp[], int left, int mid, int right); 
long long int mergeSort(int arr[], int array_size){ 
    int temp[array_size]; 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
long long int _mergeSort(int arr[], int temp[], int left, int right){ 
    long long int mid, inv_count = 0; 
    if (right > left) { 
        mid = (right + left) / 2; 
        inv_count += _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 
long long int merge(int arr[], int temp[], int left,int mid, int right){ 
    long long int i, j, k; 
    long long int inv_count = 0; 
    i = left;j = mid;k = left;
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } else { 
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i); 
        } 
    } 
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
    while (j <= right) 
        temp[k++] = arr[j++]; 
    for (i = left; i <= right; i++) 
        arr[i] = temp[i];
    re[oo][right-left+1]+=inv_count;  
    return inv_count; 
}
void solve(){
    long long int n,d;cin>>n;
    int arr[1<<n];
    int brr[1<<n];
    long long int po = 1<<n;
    for(int i=0;i<(po);i++){
        cin>>arr[i];
        brr[po-i-1]=arr[i];
    }
    mergeSort(arr,1<<n);
    oo++;
    mergeSort(brr,1<<n);
    cin>>n;
    long long int qu[21]{0};
    for(int i=0;i<n;i++){
        cin>>d;
        long long int soop = d;
        while(d>=1){
            qu[d]++;
            d--;
        }
        long long int ans = 0;
        for(int i=1;i<21;i++){
            if(qu[i]%2==0){
                ans+=re[0][1<<i];
            }else{
                ans+=re[1][1<<i];
            }
        }
        cout<<ans<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}