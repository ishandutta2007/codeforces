#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

struct dn{int x,y;}a[100001];
bool operator<(dn u,dn v){
	return u.x<v.x;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int o;
		scanf("%d",&o);
		a[o].x=i;
	}
	for(int i=1;i<=n;i++){
		int o;
		scanf("%d",&o);
		a[o].y=i;
	}
	sort(a+1,a+n+1);
	set<int>s;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s.upper_bound(a[i].y)!=s.end())
			ans++;
		s.insert(a[i].y);
	}
	printf("%d\n",ans);
}