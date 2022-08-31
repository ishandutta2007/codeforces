#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define pb push_back
#define aa first
#define bb second
#define mp make_pair
typedef long long int llo;
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
//using LL = long long;
//using PII = pair<llo, llo>;
#include <bits/stdc++.h>
using namespace std;
 
using LL = long long;
using PII = pair<llo, llo>;


llo tree[200001];
llo tree2[200001];
llo n;
void u(llo i,llo j){
	while(i<=n){
		tree[i]+=j;
		i+=(i&-i);
	}
}
llo s(llo i){
	if(i<=0){
		return 0;
	}
	llo sum=0;
	while(i>0){
		sum+=tree[i];
		i-=(i&-i);
	}
	return sum;
}
llo binary(llo v){
	llo sum=0;
	llo pos=0;
	for(llo i=20;i>=0;i--){
		if(pos+(1<<i)<n+1 and sum+tree[pos+(1<<i)]<v){
			sum+=tree[pos+(1<<i)];
			pos+=(1<<i);
		}
	}
	return pos+1;
}
void u2(llo i,llo j){
	while(i<=n){
		tree2[i]+=j;
		i+=(i&-i);
	}
}
llo s2(llo i){
	if(i<=0){
		return 0;
	}
	llo sum=0;
	while(i>0){
		sum+=tree2[i];
		i-=(i&-i);
	}
	return sum;
}
int main(){
	
	memset(tree,0,sizeof(tree));
	cin>>n;
	llo it[n];
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	llo tt[n];
	for(llo i=0;i<n;i++){
		tt[it[i]-1]=i;
	}
	llo inv=0;
	for(llo i=0;i<n;i++){
		inv+=s(n)-s(tt[i]+1);
		u(tt[i]+1,1);
		u2(tt[i]+1,tt[i]+1);
		//cout<<inv<<" ";
		
		llo tot=0;
		llo mid=binary((i+2)/2);
	//	cout<<mid<<" ";
		llo x=s(mid-1);
		tot+=(mid*x-s2(mid-1))-((x*(x+1))/2);
		//cout<<tot<<" ";
		llo y=i-x;
		tot+=((s2(n)-s2(mid)-mid*y))-(y*(y+1))/2;
		cout<<tot+inv<<" ";
		//llo mid=s.find_by_order((i+2)/2);
		

	}
	//cout<<inv<<endl;











	return 0;
}