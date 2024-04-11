/**Isn't this too easy?**/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
const int MOD = 998244353;
int n,i,ans,counti;
int a[N];
int quick[N];
int quick_space[N];
vector<int> lef;
bool missing[N];

int plusi(int a,int b)
{
    long long cur = (0LL+a+b)%MOD;
    return (int) cur;
}

int multi(int a,int b)
{
    long long cur = (1LL*a*b)%MOD;
    return (int) cur;
}

int power(int base, int pow)
{
    if(pow == 1)
        return base;
    else
    {
        int cur = power(base,pow/2);
        int get = multi(cur,cur);
        if(pow%2==1)
            get = multi(get,base);
        return get;
    }
}

int inverse(int base)
{
    return power(base,MOD-2);
}

/**Copied from Geekforgeek on counting inversion page**/
int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

/* This function sorts the input array and returns the
   number of inversions in the array */
int mergeSort(int arr[], int array_size)
{
    int* temp = (int*)malloc(sizeof(int) * array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
        inv_count = plusi(inv_count ,_mergeSort(arr, temp, left, mid));
        inv_count = plusi(inv_count, _mergeSort(arr, temp, mid + 1, right));

        /*Merge the two parts*/
        inv_count = plusi(inv_count, merge(arr, temp, left, mid + 1, right));
    }
    return inv_count;
}

/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            /*this is tricky -- see above explanation/diagram for merge()*/
            inv_count = plusi(inv_count , (mid - i));
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
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]!=-1)
            missing[a[i]-1] = true;
        if(a[i]!=-1)
        {
            lef.push_back(a[i]);
            counti++;
        }
    }
    int cur = 0, cur_space = 0;
    for(i=0;i<n;i++)
    {;
        if(!missing[i])
            cur++;
        if(a[i]==-1)
            cur_space ++;
        quick[i] = cur;
        quick_space[i] = cur_space;
    }
    int total_miss = quick[n-1];
    int inv_total_miss = inverse(total_miss);
    for(i=0;i<n;i++)
    {
        if(a[i]!=-1)
        {
            int here = i;
            int val = a[i]-1;
            int af = multi(total_miss - quick_space[here],inv_total_miss);
            af = multi(af,quick[val]);
            int bef = multi(quick_space[here],inv_total_miss);
            bef = multi(total_miss - quick[val], bef);
            af = plusi(af,bef);
            ans = plusi(ans,af);
        }
    }
    int ins = multi(total_miss,total_miss-1);
    ins = multi(ins,inverse(4));
    ans = plusi(ans,ins);
    int inv=0;
    int me[counti];
    for(i=0;i<counti;i++)
        me[i] = lef[i];
    inv = mergeSort(me,counti);
    ans = plusi(inv,ans);
    cout<<ans;
    return 0;
}