#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
int n,k,ans;
multiset<int> s;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		scanf("%d",&k);
		while(n--){
			int x;
			scanf("%d",&x);
			s.insert(x);
		}
		ans=0;
		while(!s.empty()){
			int t=*s.begin();
			ll ty=1ll*t*k;
			if(ty<=1e9){
				auto it=s.find(ty);
				if(it!=s.end()) s.erase(it);
				else ans++;
			}else ans++;
			s.erase(s.find(t));
		}
		printf("%d\n",ans);
	}
	return 0;
}