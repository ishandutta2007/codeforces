#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;  
struct Query{ 
	int l, r, idx; 
}; 
bool cmp(Query x, Query y){ 
	return x.r < y.r; 
}  
void update(int idx, int val, int bit[], int n){ 
	for (; idx <= n; idx += idx&-idx) 
		bit[idx] += val; 
} 
int query(int idx, int bit[], int n){ 
	int sum = 0; 
	for (; idx>0; idx-=idx&-idx) 
		sum += bit[idx]; 
	return sum; 
} 
int ans[1000001];
void answeringQueries(int arr[], int n, Query queries[], int q){ 
	int bit[n+1]; 
	memset(bit, 0, sizeof(bit)); 
	int last_visit[MAX]; 
	memset(last_visit, -1, sizeof(last_visit)); 
	int query_counter = 0; 
	for (int i=0; i<n; i++){ 
		if (last_visit[arr[i]] !=-1) 
			update (last_visit[arr[i]] + 1, -1, bit, n);  
		last_visit[arr[i]] = i; 
		update(i + 1, 1, bit, n); 
		while (query_counter < q && queries[query_counter].r == i){ 
			ans[queries[query_counter].idx] = 
					query(queries[query_counter].r + 1, bit, n)- 
					query(queries[query_counter].l, bit, n); 
			query_counter++; 
		} 
	} 

}  
void pre(){}
void solve(){
    int n,m;cin>>n>>m;
    int arr[n+m];
    int i = 0;
    for(;i<n;i++) arr[i]=n-i;
    for(;i<n+m;i++) cin>>arr[i];
    Query queries[m+n];
    int lst[n+1];
    for(int i=0;i<n;i++){
        lst[arr[i]]=i;
    } 
    for(int i=n;i<n+m;i++){
        queries[i-n].l=lst[arr[i]];
        queries[i-n].r=i;
        queries[i-n].idx=i-n;
        lst[arr[i]]=i;
    }
    int j = 1;
    for(int i=m;i<n+m;i++){
        queries[i].l=lst[j];
        j++;
        queries[i].r=n+m-1;
        queries[i].idx=i;
    }
    int mi[n+1];
    int ma[n+1];
    for(int i=1;i<=n;i++){mi[i]=i;ma[i]=i;}
    for(int i=n;i<n+m;i++) mi[arr[i]]=1;
    int q = sizeof(queries)/sizeof(queries[0]); 
	sort(queries, queries+q, cmp); 
	answeringQueries(arr,n+m,queries,q);
    for(int i=0;i<m;i++){
        ma[arr[i+n]]=max(ma[arr[i+n]],ans[i]);
    }
    for(int i=m;i<n+m;i++){
        ma[i-m+1]=max(ma[i-m+1],ans[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<mi[i]<<" "<<ma[i]<<"\n";
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