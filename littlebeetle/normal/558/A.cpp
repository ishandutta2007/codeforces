#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1002;
struct p{
	int x,d;
	bool operator<(const p &k)const{
		return k.d>d;
	}
}a[N],b[N];
int n,u,v,i,s,x,d,o;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&d,&x);
		if(d>0)
			a[++u]=(p){x,d};
		else
			b[++v]=(p){x,-d};
	}
	sort(a+1,a+u+1);
	sort(b+1,b+v+1);
	o=min(u,v);
	for(i=1;i<=o;i++)
		s+=a[i].x+b[i].x;
	s+=max(a[o+1].x,b[o+1].x);
	printf("%d",s);
	return 0;
}