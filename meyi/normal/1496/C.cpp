#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int n,t;
double ans;
vector<double>a,b;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		a.clear(),b.clear();
		for(ri i=1;i<=n*2;++i){
			int tmp1,tmp2;
			scanf("%d%d",&tmp1,&tmp2);
			if(!tmp1)a.push_back((double)abs(tmp2));
			else b.push_back((double)abs(tmp1));
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		if(a.size()>b.size())swap(a,b);
		ans=0;
		for(ri i=0;i<a.size();++i)ans+=sqrt(a[i]*a[i]+b[i]*b[i]);
		printf("%.12lf\n",ans);
	}
}