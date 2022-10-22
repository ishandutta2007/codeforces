#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,k,a[MAXN];
set<int> s;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		s.clear();
		scanf("%d%d",&n,&k);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),s.insert(a[i]);
		bool ans=0;
		for(int i=1; i<=n; i++)
			if(s.count(a[i]+k)) ans=1;
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}