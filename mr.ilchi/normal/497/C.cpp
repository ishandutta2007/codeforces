#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000+10;

int n,m;
int a[MAXN],b[MAXN],ans[MAXN];
int c[MAXN],d[MAXN],k[MAXN];

struct cmp{
	bool operator () (const int &i, const int &j){
		if (d[i] != d[j])
			return d[i] < d[j];
		return i < j;
	}
};

struct node{
	int lo,who,type;
	node () {}
	node (int lo, int who, int type) : lo(lo), who(who), type(type) {}
	bool operator < (const node &second) const{
		if (second.lo != lo)
			return lo < second.lo;
		return type < second.type;
	}
};

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d%d", &a[i], &b[i]);
	scanf("%d", &m);
	for (int i=0; i<m; i++) scanf("%d%d%d", &c[i], &d[i], &k[i]);
	set <int, cmp> SET;
	vector <node> Q;
	for (int i=0; i<n; i++)
		Q.push_back(node(a[i], i, 2));
	for (int i=0; i<m; i++){
		Q.push_back(node(c[i], i, 1));
		Q.push_back(node(d[i]+1,i,0));
	}
	sort(Q.begin(), Q.end());
	for (int i=0; i<(int)Q.size(); i++){
		node cur = Q[i];
		if (cur.type == 2){
			d[m] = b[cur.who]-1;
			set<int,cmp> :: iterator it = SET.upper_bound(m);
			if (it == SET.end()){
				printf("NO\n");
				return 0;
			}
			ans[cur.who] = *it;
			k[*it]--;
			if (k[*it] == 0)
				SET.erase(*it);
		}else if (cur.type == 1){	
			SET.insert(cur.who);
		}else if (cur.type == 0){
			SET.erase(cur.who);
		}
	}
	printf("YES\n");
	for (int i=0; i<n; i++)
		printf("%d ", ans[i]+1);
	printf("\n");
	return 0;
}