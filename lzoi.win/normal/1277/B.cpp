#include<cstdio>
#include<set>
using namespace std;
int n;
set<int> a;
int ans;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		while(n--){
			int x;scanf("%d",&x);
			a.insert(x);
		}
		ans=0;
		while(!a.empty()){
			set<int>::iterator it=a.end();
			it--;
			if((*it)&1) a.erase(*it);
			else ans++,a.insert((*it)/2),a.erase(*it);
		}
		printf("%d\n",ans);
	}
	return 0;
}