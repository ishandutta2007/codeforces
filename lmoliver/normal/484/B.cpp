#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1001001;
bool cnt[N];
int l[N];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]=true;
	}
	cnt[0]=true;
	for(int i=0;i<N;i++){
		l[i]=cnt[i]?i:l[i-1];
	}
	int ans=0;
	for(int i=1;i<N;i++)if(cnt[i]){
		for(int j=i;j<N;j+=i){
			int t=l[min(j+i-1,N-1)]%i;
			if(t>ans){
				// cerr<<i<<" "<<j<<endl;
				ans=t;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}