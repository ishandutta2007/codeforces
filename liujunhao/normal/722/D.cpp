#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
#define MAXN 50000
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
map<int,bool>vis;
int n,a[MAXN+10];
void read(){
	Read(n);
	int i;
	for(i=1;i<=n;i++)
		Read(a[i]);
	sort(a+1,a+n+1);
}
bool check(int mid){
	int i,t;
	vis.clear();
	for(i=1;i<=n;i++){
		t=a[i];
		while(t){
			if(t<=mid&&!vis.count(t)){
				vis[t]=1;
				break;
			}
			t>>=1;
		}
		if(!t)
			return 0;
	}
	return 1;
}
int Divide_Conqure(int l,int r){
	int mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	return l;
}
void print(){
	for(map<int,bool>::iterator i=vis.begin();i!=vis.end();i++)
		printf("%d ",i->first);
}
int main()
{
	read();
	check(Divide_Conqure(1,1000000000));
	print();
}