#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <assert.h>

#define ll long long
using namespace std;


ll _mergeSort(ll arr[], ll temp[], ll left, ll right, ll *inv_table, ll level);
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right);
  
/* This function sorts the input array and returns the
   number of inversions in the array */
ll mergeSort(ll arr[], ll array_size, ll *inv_table, ll level)
{
    ll *temp = (ll *)malloc(sizeof(ll)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1, inv_table, level);
}
  
/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
ll _mergeSort(ll arr[], ll temp[], ll left, ll right, ll *inv_table, ll level)
{
  ll mid, inv_count = 0;
  if (right > left)
  {
  	assert((level - 1) >= 0);
    /* Divide the array llo two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;
  
    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid, inv_table, level - 1);
    inv_count += _mergeSort(arr, temp, mid+1, right, inv_table, level - 1);
  
    /*Merge the two parts*/
    ll inv_interaction = merge(arr, temp, left, mid+1, right);
    inv_count += inv_interaction;
    inv_table[level-1] += inv_interaction;
  }
  return inv_count;
}
  
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right)
{
  ll i, j, k;
  ll inv_count = 0;
  
  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
  
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }
  
  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  
  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];
  
  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
  
  return inv_count;
}
int main() {
	ll n;
	cin >> n;
	ll *inv_table = new ll[n+1];
	ll *fwd_table = new ll[n+1];
	for (ll i = 0; i <= n; i++) {
		inv_table[i] = 0;
		fwd_table[i] = 0;
	}
	ll t = 1 << n;
	ll *a = new ll[t];
	ll *b = new ll[t];
	for (ll i = 0; i < t; i++) {
		scanf("%I64d", &a[i]);
		b[i] = -a[i];
	}
	mergeSort(a, t, inv_table, n);
	mergeSort(b, t, fwd_table, n);
	ll *reverse_table = new ll[n+1];
	for (ll i = 0; i <= n+1; i++) {
		reverse_table[i] = 0;
	}
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		ll q;
		cin >> q;
		reverse_table[q] ^= 1;
		ll ans = 0;
		ll state = 0;		
		for (ll k = n; k >= 0; k--) {
			ll j = n-k;
			if (k != n) {
				if (state == 0) {
					ans += inv_table[k];
				}
				else {
					ans += fwd_table[k];
				}
			}
			state ^= reverse_table[k];
		}
		cout << ans << endl;
	}
	return 0;
}