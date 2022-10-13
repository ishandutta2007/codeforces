#include<bits/stdc++.h>
using namespace std;
#define ran 111
int n,w,res[ran];
pair<int,int> a[ran];
int main(){
	scanf("%d%d",&n,&w);
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		a[i] = make_pair(x,i);
		w -= (x+1)/2;
	}
	if(w < 0){
		puts("-1");
		return 0;
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
		res[a[i].second] = (a[i].first+1)/2;
	for(int i=n; i>=1; i--){
		int lef = a[i].first / 2;
		if(w >= lef){
			res[a[i].second] = a[i].first;
			w -= lef;
		}else{
			res[a[i].second] += w;
			break;
		}
	}
	for(int i=1; i<=n; i++)
		printf("%d%c",res[i],i<n?' ':'\n');
	return 0;
}