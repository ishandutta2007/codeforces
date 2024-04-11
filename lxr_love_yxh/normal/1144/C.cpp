#include<bits/stdc++.h>
using namespace std;
int n;
int a[222222];
map<int,int>cnt;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		cnt[a[i]]++;
		if(cnt[a[i]]>2){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	set<int>inc,dec;
	for(int i=0;i<n;i++){
		if(!dec.count(-a[i]))dec.insert(-a[i]);
		else inc.insert(a[i]);
	}
	printf("%d\n",inc.size());
	for(auto x:inc)printf("%d ",x);
	printf("\n");
	printf("%d\n",dec.size());
	for(auto x:dec)printf("%d ",-x);
	printf("\n");
	return 0;
}