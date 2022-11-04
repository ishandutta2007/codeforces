#include<bits/stdc++.h>
using namespace std;
const int N=509;
struct pr{int x,y;}a[N],b[N];
bool cmp(const pr&i,const pr&j){
	if(i.x==j.x) return i.y<j.y;
	else return i.x<j.x; 
}
int main(){
	int T; cin>>T;
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;i++) a[i].x=a[i].y=b[i].x=b[i].y=0;
		for(int i=1;i<=(n+1)/2;i++) scanf("%d",&a[i].x);
		for(int i=n/2;i>=1;i--) scanf("%d",&a[i].y);
		for(int i=1;i<=(n+1)/2;i++) scanf("%d",&b[i].x);
		for(int i=n/2;i>=1;i--) scanf("%d",&b[i].y);
		for(int i=1;i<=(n+1)/2;i++){
			if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
			if(b[i].x>b[i].y) swap(b[i].x,b[i].y);
		}
		sort(a+1,a+(n+1)/2+1,cmp), sort(b+1,b+(n+1)/2+1,cmp);
		bool ans=1;
		for(int i=1;i<=(n+1)/2;i++)
			ans&=(a[i].x==b[i].x&&a[i].y==b[i].y);
		puts(ans?"Yes":"No");
	}
	return 0;
}