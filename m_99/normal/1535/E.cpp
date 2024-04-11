#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int p[300005][20];

int main(){
	
	int q;
	scanf("%d",&q);
	vector<long long> a(q+1),c(q+1);
	{
		long long a0,c0;
		cin>>a0>>c0;
		a[0] = a0,c[0] = c0;
	}
	
	rep(i,300005){
		rep(j,20){
			p[i][j] = -1;
		}
	}
	
	for(int _=1;_<=q;_++){
		int t;
		scanf("%d",&t);
		
		if(t==1){
			int P,A,C;
			scanf("%d %d %d",&P,&A,&C);
			a[_] = A;
			c[_] = C;
			
			p[_][0] = P;
			for(int j=1;j<20;j++){
				if(p[_][j-1]==-1)break;
				p[_][j] = p[p[_][j-1]][j-1];
			}
		}
		else{
			
			long long v,w;
			scanf("%lld %lld",&v,&w);
			
			long long ans = 0LL;
			long long ans0 = 0LL;
			while(w!=0 &&  a[v] != 0){
				int cur = v;
				for(int i=19;i>=0;i--){
					if(p[cur][i]==-1)continue;
					if(a[p[cur][i]]==0)continue;
					cur = p[cur][i];
				}
				long long t = min(w,a[cur]);
				a[cur] -= t;
				ans += t * c[cur];
				w -= t;
				ans0 += t;
			}
			
			cout<<ans0<<' '<<ans<<endl;
			
		}
		
	}
	
	
	return 0;
}