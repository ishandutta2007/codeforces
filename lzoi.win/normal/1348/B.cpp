#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=1e4+5;
int n,k,a[MAXN];
set<int> st;
int ans[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&k);
		st.clear();
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			st.insert(a[i]);
		}
		if(st.size()>k){
			puts("-1");
			continue;
		}
		*ans=0;
		for(set<int>::iterator it=st.begin();it!=st.end();it++)
			ans[++*ans]=*it;
		while(*ans<k)
			ans[++*ans]=1;
		printf("%d\n",n*k);
		for(int i=1; i<=n; i++)
			for(int j=1;j<=*ans;j++)
				printf("%d ",ans[j]);
		puts("");
	}
	return 0;
}