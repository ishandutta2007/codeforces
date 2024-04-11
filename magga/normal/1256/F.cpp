#include<bits/stdc++.h>
using namespace std;
long long int merge(long long int arr[],long long int temp[],long long int left,long long int mid,long long int right) { 
    long long int inv_count = 0; 
    long long int i = left; 
    long long int j = mid;
    long long int k = left;
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++]; 
        else
        { 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
        } 
    } 
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
    while (j <= right) 
        temp[k++] = arr[j++]; 
    for (i=left; i <= right; i++) 
        arr[i] = temp[i]; 
    return inv_count; 
} 
long long int _mergeSort(long long int arr[],long long int temp[],long long int left,long long int right) 
{ 
    long long int mid, inv_count = 0; 
    if (right > left) 
    { 
        mid = (right + left)/2; 
        inv_count  = _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid+1, right); 
        inv_count += merge(arr, temp, left, mid+1, right); 
    } 
    return inv_count; 
} 
long long int countSwaps(long long int arr[],long long int n) {
    long long int temp[n];
    return _mergeSort(arr, temp, 0, n - 1); 
} 
void solve(){
    long long int n;cin>>n;
    string r,s;cin>>r>>s;
    long long int arr1[n];
    long long int arr2[n];
    for(long long int i=0;i<n;i++){
        arr1[i]=int(s[i]);
    }
    for(long long int i=0;i<n;i++){
        arr2[i]=int(r[i]);
    }
    long long int b1 = countSwaps(arr1,n);
    long long int b2 = countSwaps(arr2,n);
    bool flag = true;
    for(long long int i=0;i<n;i++){
        if(arr1[i]!=arr2[i]){
            flag = false;
            break;
        }
    }
    if(!flag){
        cout<<"NO"<<"\n";
        return;
    }
    for(long long int i=1;i<n;i++){
        if(arr1[i]==arr1[i-1]){
            flag = false;
            break;
        }
    }
    if(!flag){
       cout<<"YES"<<"\n";
    }else if(b1%2==b2%2){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }
}