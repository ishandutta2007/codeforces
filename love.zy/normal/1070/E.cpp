#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
int n,m;
struct Bit {
    int sum[MAXN];
    void init() {
        memset(sum, 0, sizeof (sum));
    }
    int get(int x) {
        return x & (-x);
    }
    void add(int x) {
        for (int i = x; i <= n; i += get(i)) sum[i] += 1;
    }
    int que(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= get(i)) ans += sum[i];
        return ans;
    }
	int query(int l,int r){
		return que(r)-que(l-1);
	}
} bit;

struct node{
	long long p;
	int id;
}a[MAXN];
long long t,p[MAXN];

int baoli(int d)
{
	int i,cnt=0,c=0;
	long long pret=0,lastt=0;
	for(i=1;i<=n;i++){
		if(p[i]>d) continue;
		cnt++;c++;
		lastt+=p[i];
		if(cnt>m){
			cnt=1;
			pret+=lastt-p[i];
			lastt=p[i];
		}
		if(pret*2+lastt>t) return c-1;
	}
	return c;
}

int find(int x)
{
	int L=1,R=n,mid,res=n;
	while(L<=R){
		mid=(L+R)>>1;
		if(bit.query(mid,n)>=x){
			L=mid+1;
			res=mid;
		}
		else R=mid-1;
	}
	return res;
}

void fuck()
{
	int i;
	scanf("%d%d%lld",&n,&m,&t);
	bit.init();
	for(i=1;i<=n;i++){
		scanf("%lld",&p[i]);
		a[i].p=p[i];
		a[i].id=i;
	}
	sort(a+1,a+1+n,[](const node&x,const node&y){
			if(x.p==y.p) return x.id<y.id;
			return x.p<y.p;
			});
	long long lastid=0,pret=0,lastt=0;
	int cnt=0;
	for(i=1;i<=n;i++){
		++cnt;
		bit.add(a[i].id);
		//lastt+=a[i].p;
		int tmp=find(cnt);
		//printf("--%d\n",tmp);
		if(a[i].id>=tmp) lastt+=a[i].p;
		else{
			pret-=p[tmp];
			pret+=a[i].p;
			lastt+=p[tmp];
		}

		//update last one
		if(a[i].id>lastid) lastid=a[i].id;
		//update last group
		if(cnt>m){
			cnt=1;
			pret+=lastt-p[lastid];
			lastt=p[lastid];
		}

		if(pret*2+lastt>t) break;
	}
	i--;
	if(i==0){
		printf("0 1\n");
		return;
	}
	int t1=baoli(a[i].p);
	int t2=baoli(a[i].p-1);
	if(t1>=t2) printf("%d %d\n",t1,a[i].p);
	else printf("%d %d\n",t2,a[i].p-1);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}