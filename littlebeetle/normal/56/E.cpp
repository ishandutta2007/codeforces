#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
const int N=100002;
int n,i,x,y,s,ans[N];
set<int>S;
map<int,int>M;
struct p{
	int x,h,id;
}a[N]; 
bool cmp(p u,p v){
	return u.x>v.x;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].h);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	S.insert(1<<30);
	for(i=1;i<=n;i++){
		x=a[i].x;
		s=0;
		while((y=*S.upper_bound(x))<x+a[i].h){
			s+=M[y];
			M[y]=0;
			S.erase(y);
		}
		s++;
		M[x]=s;
		S.insert(x);
		ans[a[i].id]=s;
	}
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
}