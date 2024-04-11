#include<bits/stdc++.h>
using namespace std;
#include<bits/extc++.h>
using namespace __gnu_pbds;
gp_hash_table<int,int>fa,val;
int find(int k){
	if(fa.find(k)==fa.end())return k;
	int tmp=find(fa[k]);
	val[k]^=val[fa[k]];
	return fa[k]=tmp;
}
int lst,q;
int main(){
	scanf("%d",&q);
	while(q--){
		int op,l,r,x;
		scanf("%d%d%d",&op,&l,&r);
		l^=lst,r^=lst;
		if(l>r)swap(l,r);
		int fl=find(l),fr=find(++r);
		if(op&1){
			scanf("%d",&x);
			x^=lst;
			if(fl!=fr)fa[fl]=fr,val[fl]=val[l]^val[r]^x;
		}
		else{
			if(fl!=fr)lst=1,puts("-1");
			else printf("%d\n",lst=val[l]^val[r]);
		}
	}
	return 0;
}