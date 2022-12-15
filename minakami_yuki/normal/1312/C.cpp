#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1000;
int n,m;
LL K;
LL a[N];
bool jud(){
	for(int i=1;i<=n;++i) if(a[i]) return 1;
	return 0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%I64d",&n,&K);
		for(int i=1;i<=n;++i) scanf("%I64d",&a[i]);
		LL v=1;
		bool f=1;
		while(jud()&&f){
			int u=0;
			for(int i=1;i<=n;++i){
				if(a[i]%K>1){
					f=0;
					break;
				} 
				if(a[i]%K==1) ++u;
				a[i]=a[i]/K;
			}
			if(u>1) f=0;
		}
		if(f) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}