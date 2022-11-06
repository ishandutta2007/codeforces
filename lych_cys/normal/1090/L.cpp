#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
using namespace std;

int n,a,b,m;
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
bool check(int x){
	return ((ll)min(a,x)*(n+1>>1)+(ll)min(b,x)*(n>>1))/x>=m;
}
int main(){
	int l=0,r,mid;
	scanf("%d%d%d%d%d",&r,&n,&a,&b,&m);
	//a=min(a,r); b=min(b,r);
	while (l<r){
		mid=l+r+1>>1;
		if (check(mid)) l=mid; else r=mid-1;	
	}
	printf("%d\n",l);
	return 0;
}