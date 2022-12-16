#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200200;
int a[N];
int cnt[N];
int ccnt[N];
int mx[N];
int main(){
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cnt[i]=0;
			ccnt[i]=0;
			mx[i]=0;
		}
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		for(int i=1;i<=n;i++)ccnt[cnt[i]]++;
		for(int i=1;i<=n;i++){
			mx[cnt[i]]=max(mx[cnt[i]],i);
		}
		LL ans=0;
		for(int i=n;i>1;i--){
			if(ccnt[i]>1){
				ccnt[i-1]+=ccnt[i]-1;
				ccnt[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(ccnt[i])ans+=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}