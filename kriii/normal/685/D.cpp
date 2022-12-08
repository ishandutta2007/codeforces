#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

struct intv{
	intv(){}
	intv(int y_, int l_, int r_, int p_){
		y = y_; l = l_; r = r_; p = p_;
	}
	int y,l,r,p;
	bool operator <(const intv &i) const{return y < i.y;}
}I[200020];

int list[200020],cnt[200020],last[200020];
long long ans[100010];

int main()
{
	int N,K,C=0;
	scanf ("%d %d",&N,&K);
	for (int i=0;i<N;i++){
		int x,y; scanf ("%d %d",&x,&y);
		I[C] = intv(y-K,x-K,x,1);
		list[C++] = x-K;
		I[C] = intv(y,x-K,x,-1);
		list[C++] = x;
	}
	sort(I,I+C);
	sort(list,list+C);
	C = unique(list,list+C) - list;

	for (int i=0;i<2*N;i++){
		int s = lower_bound(list,list+C,I[i].l) - list;
		while (list[s] < I[i].r){
			int e = s + 1;
			ans[cnt[s]] += ((long long)I[i].y - last[s]) * (list[e] - list[s]);
			cnt[s] += I[i].p;
			last[s] = I[i].y;
			s = e;
		}
	}

	for (int i=1;i<=N;i++) printf ("%lld ",ans[i]);
	return 0;
}