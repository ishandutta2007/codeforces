#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200200;
struct Node{
	LL id,v,ans;
	Node(){

	}
}a[N];
struct Ind{
	LL id,v;
	Ind(){}
	Ind(LL _id,LL _v){
		id=_id,v=_v;
	}
};
bool operator <(const Ind a,const Ind b){
	return a.v>b.v;
}
set<Ind> q;
bool operator <(const Node a,const Node b){
	return a.v<b.v;
}
LL an[N];
int main(){
	LL n,m,d;
	scanf("%I64d%I64d%I64d",&n,&m,&d);
	for(int i=0;i<n;i++){
		a[i].id=i;
		scanf("%I64d",&a[i].v);
	}
	sort(a,a+n);
	int ans=0;
	for(int i=0;i<n;i++){
		set<Ind>::iterator inn=q.lower_bound(Ind(0,a[i].v-d-1));
		LL mm=inn==q.end()?0x7fffffffffffffff:inn->v+d;
		if(a[i].v<=mm){
			a[i].ans=ans;
			q.insert(Ind(ans,a[i].v));
			ans++;
		}else{
			Ind mi=*inn;
			q.erase(inn);
			a[i].ans=mi.id;
			mi.v=a[i].v;
			q.insert(mi);
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<n;i++){
		an[a[i].id]=a[i].ans;
	}
	for(int i=0;i<n;i++){
		printf("%I64d ",an[i]+1);
	}
	return 0;
}