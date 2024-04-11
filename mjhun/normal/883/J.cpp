#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int n,m;
int a[100005],b[100005],p[100005];
int z[100005];
ll s;
priority_queue<int> q;
vector<int> w[100005];

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,0,m)scanf("%d",b+i);
	fore(i,0,m)scanf("%d",p+i);
	for(int i=n-1;i>=0;--i)z[i]=-max(a[i],-z[i+1]);
	fore(i,0,m){
		int k=upper_bound(z,z+n,-b[i])-z-1;
		if(k>=0)w[k].pb(p[i]);
	}
	fore(i,0,n){
		s+=a[i];
		for(int k:w[i]){
			if(k<=s)s-=k,q.push(k);
			else if(!q.empty()&&q.top()>k){
				s+=q.top()-k;q.pop();q.push(k);
			}
		}
	}
	printf("%d\n",SZ(q));
	return 0;
}