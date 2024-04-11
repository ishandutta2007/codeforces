#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=1e5+5;
int n,p[MAXN],q[MAXN];
int l[MAXN],r[MAXN];
multiset<int> s;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",p+i),q[p[i]]=i,l[i]=i-1,r[i]=i+1,s.insert(1);
		r[0]=1;
		l[n+1]=n;
		bool ans=1;
		for(int i=1; i<=n; i++){
			multiset<int>::iterator it=s.end();
			it--;
			if(q[i]-l[q[i]]<*it){
				ans=0;
				break;
			}
			l[r[q[i]]]=l[q[i]];
			r[l[q[i]]]=r[q[i]];
			s.erase(s.find(q[i]-l[q[i]]));
			if(r[q[i]]<=n){
				s.erase(s.find(r[q[i]]-q[i]));
				s.insert(r[q[i]]-l[q[i]]);
			}
		}
		if(ans) puts("Yes");
		else puts("No");
		s.clear();
	}
	return 0;
}