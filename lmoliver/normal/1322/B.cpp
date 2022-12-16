#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int L=25;
const int N=1<<L;
const int NN=400400;
int n;
int a[NN];
int cnt[N]={0};
#define G(X) ((X)>=0?((X)>=2*x)?cnt[2*x-1]:cnt[X]:0)
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	// int tans=0;
	// for(int i=0;i<n;i++){
	// 	for(int j=i+1;j<n;j++){
	// 		tans^=(a[i]+a[j]);
	// 	}
	// }
	// cerr<<tans<<endl;
	int ans=0;
	for(int j=L-1;j>=0;j--){
		int x=1<<j;
		LL sum=0;
		// cerr<<j<<endl;
		// for(int i=0;i<2*x;i++){
		// 	cerr<<cnt[i]<<" ";
		// }
		// cerr<<endl;
		for(int i=1;i<2*x;i++){
			cnt[i]+=cnt[i-1];
		}
		for(int i=2*x-1;i>=0;i--){
			int w=G(i)-G(i-1);
			if(w>0){
				int d=(G(4*x-1-i)-G(3*x-1-i)+G(2*x-1-i)-G(x-1-i));
				// cerr<<i<<" "<<w<<" "<<d<<endl;
				sum+=(LL)d*w;
			}
		}
		for(int i=2*x-1;i>0;i--){
			cnt[i]-=cnt[i-1];
		}
		for(int i=2*x-1;i>=0;i--){
			if((x<=i+i&&i+i<2*x)||(3*x<=i+i&&i+i<4*x)){
				sum-=(LL)cnt[i];
			}
		}
		sum/=2;
		// cerr<<"sum = "<<sum<<endl;
		ans^=(sum&1)<<j;
		for(int i=x;i<2*x;i++){
			cnt[i^x]+=cnt[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}