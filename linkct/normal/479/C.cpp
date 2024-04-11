#include <cstdio>
#include <algorithm>
#define MAXN 5005
using std :: sort;

int n, restime;
struct data{
	int a, b;
	int getTime() const{
		return b < restime ? a : b;
	}
	bool operator < (const data& rhs) const{
		return a == rhs.a ? b < rhs.b : a < rhs.a;
	}
}seq[MAXN];

bool cmp(const data& a, const data& b){
	return a.getTime() < b.getTime();
}
int main(){
	int i, pos;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%d%d", &seq[i].a, &seq[i].b);
	sort(seq + 1, seq + 1 + n);
	for(pos = 1, i = 2; i <= n; ++ i)
		if(seq[i].a != seq[i - 1].a){
			sort(seq + 1 + pos, seq + 1 + i, cmp);
			restime = seq[i].getTime();
			pos = i;
		}
	sort(seq + 1 + pos, seq + 1 + n, cmp);
	printf("%d\n", seq[n].getTime());
	return 0;
}