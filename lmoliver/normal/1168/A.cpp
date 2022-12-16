#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=300300;
int n,m;
int a[N];
int b[N];
bool judge(int x){
	for(int i=0;i<n;i++){
		b[i]=a[i];
	}
	int o=0;
	for(int i=0;i<n;i++){
		if(b[i]<=o){
			if(x<o-b[i]){
				return false;
			}
			else{
				b[i]=o;
			}
		}
		else if(x>=m+o-b[i]){
			b[i]=o;
		}
		o=b[i];
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int l=0;
	int r=m;
	while(l<r){
		int mid=(l+r)>>1;
		if(judge(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	printf("%d\n",l);
	return 0;
}