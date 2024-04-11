#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set p;
set<int> w[256];
char s[200005];
int n,m;

int main(){
	scanf("%d%d%s",&n,&m,s);
	fore(i,0,n)w[s[i]].insert(i),p.insert(i);
	while(m--){
		int l,r;char t[4];
		scanf("%d%d%s",&l,&r,t);l--;r--;
		l=*p.find_by_order(l);r=*p.find_by_order(r);
		auto it=w[t[0]].lower_bound(l);
		vector<int> z;
		while(it!=w[t[0]].end()&&*it<=r){
			z.pb(*it);
			p.erase(*it);
			++it;
		}
		for(int x:z)w[t[0]].erase(x);
	}
	for(int i:p)putchar(s[i]);
	puts("");
	return 0;
}