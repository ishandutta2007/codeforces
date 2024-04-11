# include <iostream>
# include <cstdio>
# include <map>
using namespace std;
const int MAXN = 200005;
const int MAXM = 200005;
int b[MAXM], m;

class Count{
	private:
		map<int,int> s, t;
		int spare;
	public:
	void init() {
		spare = 0;
		s.clear();
		t.clear();
		for(int i=0; i<m; i++)
			s[b[i]]++;
	}
	void add(int x) {
		t[x] ++;
		if(t[x] > s[x])
			spare ++;
	}
	void del(int x) {
		if(t[x] > s[x])
			spare --;
		t[x] --;
	}
	bool legal() {
		return spare == 0;
	}
} c;

bool ans[MAXN]; int n, p, a[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&p);
	long long maxp = n - 1LL * m * p;
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	for(int i=0; i<m; i++) scanf("%d", &b[i]);
	for(int i=0; i<p; i++)
		if(i<maxp+p) {
			c.init();
			for(int j=i,k=0;k<m;j+=p,k++) {
				c.add(a[j]);
			}
			for(int j=i; j<n; j+=p) {
				if(c.legal()) ans[j] = true;
				c.del(a[j]);
				if(j<maxp) c.add(a[j+m*p]);
				else break;
			}
		}
	int count = 0;
	for(int i=0; i<n; i++)
		if(ans[i]) count++;
	printf("%d\n", count);
	for(int i=0; i<n; i++)
		if(ans[i]) printf("%d ", i+1);
	printf("\n");
	return 0;
}