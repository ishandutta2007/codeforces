#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int N=102;
struct p{
	int l,r,id;
	bool operator<(const p &k)const{
		if(k.r!=r)
			return k.r>r;
		return k.l>l;
	}
}a[N];
int n,i,j,s[N];
map<int,bool>p;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i;
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		for(j=a[i].l;j<=a[i].r;j++)
			if(!p[j]){
				p[j]=1;
				s[a[i].id]=j;
				break;
			}
	}
	for(i=1;i<=n;i++)
		printf("%d ",s[i]);
}