#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,t;
int s,d;
int main(){
	cin>>n>>t;
	int la=0;
	int mn=0x3f3f3f3f,p=1;
	for(int i=1;i<=n;i++){
		cin>>s>>d;
		if(t<=s){
			if(mn>s){
				mn=s;
				p=i;
			}
			continue;
		}
		int tmp=((t-s-1)/d+1)*d+s;
		if(mn>tmp){
				mn=tmp;
				p=i;
			}
			continue;
	}
	printf("%d",p);
	return 0;
}