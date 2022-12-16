#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,int> P;
const int N=100100;
int a[N];
int b[N];
int n;
LL k;
LL ww(LL x){
	return (-3*x+3)*x-1;
}
bool test(LL x){
	// cerr<<"test "<<x<<endl;
	LL cnt=0;
	for(int i=1;i<=n;i++){
		int l=0,r=a[i];
		while(l<r){
			int mid=l+((r-l+1)>>1);
			if(a[i]+ww(mid)>=x){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		b[i]=l;
		cnt+=l;
	}
	return cnt>=k;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	priority_queue<P> q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(P(a[i]+ww(1),i));
	}
	LL l=-4e18,r=4e18;
	while(l<r){
		LL mid=l+((r-l+1)>>1);
		if(test(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	// cerr<<l<<" "<<r<<endl;
	test(l);
	LL cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=b[i];
	}
	for(int i=1;i<=n;i++){
		while(b[i]>0&&cnt>k&&a[i]+ww(b[i])==l){
			b[i]--;
			cnt--;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	return 0;
}