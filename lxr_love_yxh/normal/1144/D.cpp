#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int n;
int a[222222];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)mp[a[i]]++;
	int mx=-1,cnt=0,pos;
	for(map<int,int>::iterator itr=mp.begin();itr!=mp.end();itr++){
		int key=itr->first,val=itr->second;
		if(val>mx){
			mx=val;cnt=key;
		}
	}
	for(int i=0;i<n;i++)if(a[i]==cnt)pos=i;
	printf("%d\n",n-mx);
	for(int i=pos+1;i<n;i++){
		printf("%d %d %d\n",a[i-1]>a[i]?1:2,i+1,i);a[i]=a[i-1];
	}
	for(int i=pos;i>=0;i--){
		if(a[i]!=cnt){
			printf("%d %d %d\n",a[i]<a[i+1]?1:2,i+1,i+2);a[i]=a[i+1];
		}
	}
	return 0;
}