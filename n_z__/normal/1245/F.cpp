#include<bits/stdc++.h>
using namespace std;
#define int long long
int w2(int l,int r){
	int ret=0,k=0;
	for(int x=1;r;x*=2){
		if(r&x)
		if(!(l&(r^=x)))ret+=1<<k;
		if(!(l&x))k++; 
	}
	return ret;
}
int w1(int l,int r){
	if(l==r-1)return !l;
	if(l&1)return w1(l+1,r)+2*(w2(l,r)-w2(l,l));
	if(r&1)return w1(l,r-1)+2*(w2(r-1,r)-w2(r-1,l));
	return 3*w1(l/2,r/2);
}
signed main(){
	int t;
	cin>>t;
	while(t--)
	{
		int l,r;
		cin>>l>>r;
		cout<<w1(l,r+1)<<endl;
	}
}