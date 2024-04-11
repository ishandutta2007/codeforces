#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],m,n,t_case;
inline bool check(){
	ri l=1,r=n;
	deque<int>q;
	while(l<=r){
		if(b[l]<b[r])q.push_front(b[l++]);
		else q.push_back(b[r--]);
	}
	bool flag1=true,flag2=true;
	for(ri i=1;i<n;++i){
		flag1&=(q.front()==a[i]);
		flag2&=(q.front()==a[i+1]);
		q.pop_front();
	}
	if(!flag1&&!flag2)return false;
	for(ri i=1;i<=n;++i)printf("%d ",b[i]);
	printf("\n");
	return true;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ri l=1,r=n,pos;
		deque<int>q;
		while(l<=r){
			if(l==r){pos=l;break;}
			else if(a[l]<a[r])q.push_front(l++);
			else q.push_back(r--);
		}
		ri cnt=0;
		for(auto i:q)b[++cnt]=a[i];
		b[++cnt]=a[pos];
		if(check())continue;
		b[cnt=1]=a[pos];
		for(auto i:q)b[++cnt]=a[i];
		if(check())continue;
		puts("-1");
	}
	return 0;
}