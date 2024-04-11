#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[301],c[301],tmpA[301];
pair<int,int>b[301];
int cnt;
void merge_sort(int l, int r, int *A) {
	if (l >= r) return ;
	int mid = (l + r) >> 1;
	merge_sort(l, mid, A);
	merge_sort(mid + 1, r, A);
	int pl = l, pr = mid + 1, tmpp = 0;
	while(pl <= mid && pr <= r) {
		if (A[pl] <= A[pr]) tmpA[tmpp++] = A[pl++];
		else tmpA[tmpp++] = A[pr++], cnt += mid - pl + 1;
	}
	while(pl <= mid) tmpA[tmpp++] = A[pl++];
	while(pr <= r) tmpA[tmpp++] = A[pr++];
	for (int i = 0; i < tmpp; i++) A[i + l] = tmpA[i];
} 
main()
{
    int t;cin>>t;while(t--){
        int n,m;
        cin>>n>>m;
        for(int x=1;x<=m;x++)
        cin>>a[x],b[x].first=a[x],b[x].second=-x;
        sort(b+1,b+1+m);
        for(int x=1;x<=m;x++)
        c[-b[x].second]=-x;
        //for(int x=1;x<=m;x++)cout<<c[x]<<' ';cout<<endl;
        cnt=0;
        merge_sort(1,m,c);
        cout<<cnt<<endl;
    }
}