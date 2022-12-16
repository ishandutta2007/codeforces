#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100100;
void answer(bool isTokitsukazeWinner){
	puts(isTokitsukazeWinner?"sjfnb":"cslnb");
	exit(0);
}
int n;
LL a[N];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	bool flag=false;
	for(int i=0;i<n-1;i++){
		if(a[i]==a[i+1]){
			if(a[i]==0||flag)answer(false);
			flag=true;
			a[i]--;
			if(i>0&&a[i]==a[i-1])answer(false);
		}
	}
	LL steps=flag?1:0;
	for(int i=0;i<n;i++){
		steps+=a[i]-i;
	}
	answer(steps%2==1);
	return 0;
}