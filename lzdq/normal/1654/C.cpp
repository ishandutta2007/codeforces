#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
multiset<ll> s1,s2;
ll sum;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		s1.clear();
		s2.clear();
		scanf("%d",&n);
		sum=0;
		while(n--){
			int x;
			scanf("%d",&x);
			s1.insert(ll(x));
			sum+=x;
		}
		s2.insert(sum);
		while(!s1.empty()&&s2.size()<=s1.size()){
			auto it=s2.end();
			it--;
			ll x=*it;
			s2.erase(it);
			it=s1.find(x);
			if(it!=s1.end()){
				s1.erase(it);
				continue;
			}
			s2.insert(x>>1);
			s2.insert(x+1>>1);
		}
		if(s1.empty()&&s2.empty()) puts("yes");
		else puts("no");
	}
	return 0;
}