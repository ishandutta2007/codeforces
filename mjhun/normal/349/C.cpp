#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int a[100005];
int n;

long long int result(){
	int m=a[n-1], i;
	long long int s=0;
	for(i=0;i<n-1;++i){
		s+=m-a[i];
	}
	if(s>=m)return m;
	m-=s;
	s+=(m/(n-1))*n;
	m%=n-1;
	if(m>0)
		s+=m+1;
	return s;
}

int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",a+i);
	}
	sort(a,a+n);
	cout<<result()<<endl;
	return 0;
}