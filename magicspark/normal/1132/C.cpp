#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,q;
int l[5555],r[5555];
int sum1[5555],sum2[5555],sum3[5555];//1:sum 2:sum for >1
int a[5555];
void add(int l,int r){
	for(int i=l;i<=r;i++)a[i]++;
}
int main(){
	cin>>n>>q;
	for(int i=0;i<q;i++)cin>>l[i]>>r[i],add(l[i],r[i]);
	for(int i=1;i<=n;i++)sum1[i]=sum1[i-1]+(a[i]>0),sum2[i]=sum2[i-1]+(a[i]>1),sum3[i]=sum3[i-1]+(a[i]>2);
	int ans=0;
	for(int i=0;i<q;i++)
		for(int j=i+1;j<q;j++){
			int l1=l[i],l2=l[j],r1=r[i],r2=r[j];
			if(l1>l2){
				swap(l1,l2);
				swap(r1,r2);
			}
			if(r1<l2){
				ans=max(ans,sum1[l1-1]+sum2[r1]-sum2[l1-1]+sum1[l2-1]-sum1[r1]+sum2[r2]-sum2[l2-1]+sum1[n]-sum1[r2]);
			}else{
				int ll=max(l1,l2),rr=min(r1,r2);l1=min(l1,l2);r1=max(r1,r2);
				ans=max(ans,sum1[l1-1]+sum2[ll-1]-sum2[l1-1]+sum3[rr]-sum3[ll-1]+sum2[r1]-sum2[rr]+sum1[n]-sum1[r1]);
			}
		//	cerr<<i<<" "<<j<<" "<<ans<<endl;
		}
	cout<<ans<<endl;
	return 0;
}