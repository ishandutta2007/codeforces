#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int n,lst,Lst,i,l,r;
struct Nod{
	int x,y,z,id;
	bool operator<(const Nod &k)const{
		if(k.z!=z)return k.z<z;
		if(k.y!=y)return k.y<y;
		return k.x<x;
	}
}a[N];
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		a[i].id=i;
	}
	sort(a+1,a+n+1);
}
void work3(int L,int R){
	int i;
	for(i=L;i<R;i+=2)
		printf("%d %d\n",a[i].id,a[i+1].id);
	if(i==R){
		if(lst)
			printf("%d %d\n",lst,a[i].id),lst=0;
		else
			lst=a[i].id;
	}
}
void work2(int L,int R){
	int l,r;
	for(l=L;l<=R;l++){
		for(r=l;a[r].y==a[r+1].y&&r<R;r++);
		work3(l,r);
		l=r;
	}
}
void work(){
	a[n+1]=(Nod){(int)1e9,(int)1e9,(int)1e9};
	int l,r;
	for(l=1;l<=n;l=r+1){
		for(r=l;a[r].z==a[r+1].z;r++);
		work2(l,r);
		l=r;
		if(lst){
			if(!Lst)
				Lst=lst,lst=0;
			else
				printf("%d %d\n",lst,Lst),lst=0,Lst=0;
		}
	}
}
int main(){
	init();
	work();
	//while(1);
	return 0;
}