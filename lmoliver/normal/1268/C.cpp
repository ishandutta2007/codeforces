#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200200;
int n;
int p[N];
struct BIT{
	LL a[N];
	void add(int x,int v=1){
		for(;x<N;x+=x&-x){
			a[x]+=v;
		}
	}
	LL query(int x){
		LL ans=0;
		for(;x>0;x-=x&-x){
			ans+=a[x];
		}
		return ans;
	}
	int kth(int k){
		int l=1,r=N-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(query(mid)>=k){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		return l;
	}
};
BIT s1,s2;
int pos[N];
LL ss(LL x){
	return x*(x+1)/2;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		pos[p[i]]=i;
	}
	LL sum=0;
	LL nx=0;
	for(int i=1;i<=n;i++){
		int x=pos[i];
		sum+=x;
		s1.add(x);
		nx+=i-s1.query(x);
		s2.add(x,x);
		int mm=(i+1)/2;
		int mid=s1.kth(mm);
		// cerr<<mid<<endl;
		LL lp=s2.query(mid);
		LL rp=sum-lp;
		// cerr<<i<<" "<<lp<<" "<<rp<<" "<<mid<<endl;
		LL ans=nx+((LL)mid*mm-lp)+(rp-(LL)mid*(i-mm))-ss(mm-1)-ss(i-mm);
		cout<<ans<<" ";
		// cerr<<endl;
	}
	cout<<endl;
	return 0;
}