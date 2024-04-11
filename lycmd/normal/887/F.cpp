#include<bits/stdc++.h>
using namespace std;
int const N=2333333;
int n,k,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2,j=1,flg=0;i<=n;i++){
		if(a[i]<a[j]){
			j=i;
		}else if(i-j>=k){
			if(flg)
				cout<<"NO\n",exit(0);
			flg=1;
			int p=0;
			for(int x=i+1;x<=n;x++)
				if(a[p]<a[x]&&a[x]<a[j])
					p=x;
			if(!p)
				cout<<"NO\n",exit(0);
			swap(a[j+=k],a[p]);
		}
	}
	cout<<"YES\n";
}