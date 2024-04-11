#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200200;
int n;
char s[N];
int a[N];
int cnt[N][2];
int l0[N];
int r0[N];
int id[N];
int hs[N];
const int MOD=1010000011;
const int BASE=2333;
int add(int a,int b){
	return (a+b)%MOD;
}
int sub(int a,int b){
	return (a-b+MOD)%MOD;
}
int mul(int a,int b){
	return (LL)a*b%MOD;
}
int ksm(int a,int b){
	if(b==0){
		return 1;
	}
	int x=ksm(a,b>>1);
	x=mul(x,x);
	if(b&1)x=mul(x,a);
	return x;
}
void init(){
	int c0=0;
	int b=1;
	for(int i=1;i<=n;i++){
		a[i]=s[i]^'0';
		cnt[i][0]=cnt[i-1][0];
		cnt[i][1]=cnt[i-1][1];
		cnt[i][a[i]]++;
		l0[i]=a[i]==0?i:l0[i-1];
		if(a[i]==0){
			id[i]=++c0;
			if(c0>1){
				hs[c0]=add(hs[c0-1],mul(b,(i-1-l0[i-1])%2));
				// cerr<<"h "<<i<<" "<<c0<<" "<<hs[c0]<<endl;
				b=mul(b,BASE);
			}
			else{
				hs[c0]=0;
			}
		}
	}
	for(int i=n;i>=1;i--){
		r0[i]=a[i]==0?i:r0[i+1];
	}
	// for(int i=1;i<=n;i++){
	// 	cerr<<i<<" "<<l0[i]<<" "<<r0[i]<<endl;
	// }
}
tuple<int,int,int> qaq(int l,int r,int hmul){
	int ll=r0[l];
	int rr=l0[r];
	int pl=(ll-l)%2;
	int pr=(r-rr)%2;
	int h=mul(sub(hs[id[rr]],hs[id[ll]]),hmul);
	// cerr<<l<<" "<<r<<" "<<hmul<<" -> "<<pl<<" "<<pr<<" "<<h<<endl;
	return tuple<int,int,int>{pl,pr,h};
}
bool query(int l1,int l2,int len){
	if(l2<l1){
		swap(l1,l2);
	}
	int cc=cnt[l1+len-1][0]-cnt[l1-1][0];
	if(cc!=cnt[l2+len-1][0]-cnt[l2-1][0]){
		return false;
	}
	if(cc==0){
		return true;
	}
	return qaq(l1,l1+len-1,ksm(BASE,id[r0[l2]]-id[r0[l1]]))==qaq(l2,l2+len-1,1);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>(s+1);
	init();
	int q;
	cin>>q;
	// cerr<<"QWQ"<<endl;
	while(q--){
		int l1,l2,len;
		cin>>l1>>l2>>len;
		puts(query(l1,l2,len)?"YES":"NO");
	}
	return 0;
}