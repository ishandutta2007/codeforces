#include<bits/stdc++.h>
using namespace std;
void pre(){}
struct Query{ long long int l, r, x, idx;}; 
struct ArrayElement{long long int val, idx;}; 
bool cmp1(Query q1, Query q2){ return q1.x < q2.x;} 
bool cmp2(ArrayElement x, ArrayElement y){ return x.val < y.val;} 
void update(long long int bit[],long long int idx,long long int val,long long int n){ 
    for (; idx<=n; idx +=idx&-idx) 
        bit[idx] += val; 
} 
long long int query(long long int bit[],long long int idx,long long int n){ 
    long long int sum = 0; 
    for (; idx > 0; idx -= idx&-idx) 
        sum += bit[idx]; 
    return sum; 
} 
vector<long long int> answerQueries(long long int n, Query queries[],long long int q, ArrayElement arr[]){ 
    long long int bit[n+1];
    vector<long long int>ret;
    memset(bit, 0, sizeof(bit)); 
    sort(arr, arr+n, cmp2); 
    sort(queries, queries+q, cmp1); 
    long long int curr = 0; 
    long long int ans[q]; 
    for (long long int i=0; i<q; i++){ 
        while (arr[curr].val <= queries[i].x && curr<n){ 
            update(bit, arr[curr].idx+1, 1, n); 
            curr++; 
        } 
        ans[queries[i].idx] = 
        query(bit, queries[i].r+1, n) - query(bit, queries[i].l, n); 
    } 
    for (long long int i=0 ; i<q; i++) {
        ret.push_back(ans[i]);
    }
    return ret;
} 
void solve(){
    long long int n;cin>>n;
    pair<long long int,long long int>arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i].first;
    }
    for(long long int i=0;i<n;i++){
        cin>>arr[i].second;
    }
    sort(arr,arr+n);
    ArrayElement ar[n];
    ArrayElement br[n];
    for(long long int i=0;i<n;i++){
        ar[i].val=arr[i].second;
        ar[i].idx=i;
        br[i].val=-1*arr[i].second;
        br[i].idx=i;
    }
    Query queries[n];
    Query queries2[n];
    for(long long int i=0;i<n;i++){
        queries[i].l=0;
        queries[i].r=i;
        queries[i].x=arr[i].second;
         queries[i].idx=i;
         queries2[i].idx=i;
        queries2[i].l=i;
        queries2[i].r=n-1;
        queries2[i].x=-1*arr[i].second;
    }
    vector<long long int>calc=answerQueries(n, queries, n, ar);
    vector<long long int>calc2=answerQueries(n, queries2, n, br);
    long long int ans = 0;
    for(long long int i=0;i<n;i++){
        ans+=arr[i].first*(calc[i]-calc2[i]);
    }
    cout<<ans<<"\n";
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