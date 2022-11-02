#include<cstdio>
#include<queue>
using namespace std;
const int N=200002;
int n,i,s,R,Rp,T[N];
struct p{
	int l,r,id;
	bool operator<(const p &k)const{
		return k.l==l?k.r>r:k.l<l;
	}
}x,y;
priority_queue<p>Q;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x.l,&x.r);
		x.id=i;
		Q.push(x);
	}
	R=-1;
	while(!Q.empty()){
		if((Q.top()).l<=R+1){
			y.r=-1;
			while(!Q.empty()&&(Q.top()).l<=R+1){
				x=Q.top();
				Q.pop();
				if(x.r>y.r)
					y=x;
			}
			if(y.r>R)
			T[y.id]=1,
			R=y.r;
		}
		else{
			x=Q.top();
			Q.pop();
			T[x.id]=1;
			R=x.r;
		}
	}
	for(i=1;i<=n;i++)
		if(!T[i]){
			printf("%d",i);
				return 0;
		}
	printf("-1");
}/////