#include<bits/stdc++.h>
using namespace std;
#define ran 111111
int b[ran],n;
pair<int,int> a[ran];
bool ff[ran];
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	for(int i=0; i<n; i++)
		scanf("%d",&b[i]);
	bool flag = false;
	if(n % 2 == 0){
		a[n] = make_pair(0,n);
		b[n] = 0;
		n++;
		flag = true;
	}
	sort(a,a+n);
	long long int sum1 = 0, sum2 = 0;
	for(int i=0; i<n-1; i+=2){
		sum1 += b[a[i].second];
		sum2 += b[a[i+1].second];
	}
	ff[a[n-1].second] = true;
	if(sum1 > sum2){
		for(int i=0; i<n-1; i+=2)
			ff[a[i].second] = true;
	}else{
		for(int i=0; i<n-1; i+=2)
			ff[a[i+1].second] = true;
	}
	if(flag){
		n--;
	}
	int cnt=0;
	for(int i=0; i<n; i++)
		if(ff[i])
			cnt++;
	printf("%d\n",cnt);
	for(int i=0; i<n; i++)
		if(ff[i])
		printf("%d%c",i+1,--cnt==0?'\n':' ');
	return 0;
}