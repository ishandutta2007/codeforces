#include <cstring>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cmath>
#define ll long long
#define maxn 2020
using namespace std;
int n;
struct yqh{
	int l,r;
	int sum;
}a[200020];
int sum[maxn][maxn][8];
int mp[maxn][maxn];
int position[maxn*maxn];
int b[maxn];
int rgt;
ll ans;
void create(int r,int x,int y){
	a[r].l = x;
	a[r].r = y;
	a[r].sum = 0;
	if(x == y){
		return;
	}
	int mid = (x+y) >> 1;
	create(r<<1,x,mid);
	create(r<<1|1,mid+1,y);
}
void insert(int r){
	++ a[r].sum;
	if(a[r].l == a[r].r)return;
	int mid = a[r<<1].r;
	if(rgt <= mid) insert(r<<1);else insert(r<<1|1);
}
int query(int r){
	if(rgt >= a[r].r)return a[r].sum;
	int mid = a[r<<1].r;
	if(mid >= rgt) return query(r<<1);
	return query(r<<1) + query(r<<1|1);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)for(int j=0;j<n;++j){
		scanf("%d",&mp[i][j]);
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			b[j] = mp[i][j];
		}
		sort(b,b+n);
		for(int j=0;j<n;++j){
			position[b[j]] = j;
		}
		//create(1,0,n-1);
		for(int j=0;j<n;++j){
		//	rgt = position[mp[i][j]];
			sum[i][j][0] = position[mp[i][j]];
			sum[i][j][1] = n - 1 - sum[i][j][0];
		}
		for(int j=0;j<n;++j){
			b[j] = mp[j][i];
		}
		sort(b,b+n);
		for(int j=0;j<n;++j){
			position[b[j]] = j;
		}
		//create(1,0,n-1);
		for(int j=0;j<n;++j){
			sum[j][i][2] = position[mp[j][i]];
			sum[j][i][3] = n - 1 - sum[j][i][2];
		}		
		
	}
	ans = 0;
	for(int i=0;i<n;++i)for(int j=0;j<n;++j){
		ans += sum[i][j][0] * sum[i][j][3];
		ans += sum[i][j][1] * sum[i][j][2];
	}
	printf("%lld\n", ans/2);
    return 0;
}