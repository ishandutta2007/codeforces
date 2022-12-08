#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
long long n,cnt,a[N],bit[N],xo;
unordered_map<int,int> idx,cut;
long long solve(int mask){
	int cunt[32];
//	cout<<mask<<" YES\n";
	if(mask==1) return 0;
	if(idx[mask]) return idx[mask];
//	if(cut[mask]==0) return cut[mask];
	for(int i=0;i<=30;i++)
	{
		if((1<<i)>mask) break;
		cunt[i]=0;
	}
//	for(int i=1;i<=30;i++){
//		if((1<<i)-1>=mask) break;
//		cout<<((mask>>i)|(mask&((1<<i)-1)))<<" "<<i<<endl;
////		cunt[solve(((mask>>i)|(mask&((1<<i)-1))))]=1;
//	}
	for(int i=1;i<=30;i++){
		if((1<<i)-1>=mask) break;
//		cout<<((mask>>i)|(mask&((1<<i)-1)))<<endl;
		cunt[solve(((mask>>i)|(mask&((1<<i)-1))))]=1;
	}
	int ans=0;
	while(cunt[ans]==1){
		ans++;
	}
//	cou
//	cut[mask]=ans;
	idx[mask]=ans;
	return ans;
}
signed main(){
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(int i=2; i*i<=1000000000; i++)
	{
		int maskk=0;
		for(int j=1; j<=n; j++)
		{
			int cac=0;
			while(a[j]%i==0)
			{
				cac++;
				a[j]/=i;
			}
			if(cac) maskk|=(1<<cac);
		}
		if(!maskk) continue;
//		cout<<maskk<<endl;
		xo^=solve(maskk);
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
	{
		if(a[i]>1&&a[i]!=a[i-1])
		{
//			cout<<2<<endl;
			xo^=solve(2);
		}
	}
//	for(int i=1;i<=n;i++){ 
//		cin >> a[i];
//		for(int j=2;j<=sqrt(a[i]);j++){
//			if(a[i]%j==0){
//				int dem=0;
//				while(a[i]%j==0){
//					a[i]=a[i]/j;
//					dem++;
//				}
//				if(idx[j]==0){
//					cnt++;
//					bit[cnt]=bit[cnt]|(1<<(dem-1));
//					idx[j]=cnt;
//				}else{
//					bit[idx[j]]=bit[idx[j]]|(1<<(dem-1));
//				}
//			}
//		}
//		if(a[i]>1){
//			if(idx[a[i]]==0){
//				cnt++;
//				bit[cnt]=bit[cnt]|1;
//				idx[a[i]]=cnt;
//			}else{
//				bit[idx[a[i]]]=bit[idx[a[i]]]|1;
//			}
//		}
//	}
//	for(int i=1;i<=cnt;i++){
//		xo=xo^solve(bit[i]);
//	}
//cout<<idx[6]<<endl;
	if(xo>0){
		cout<<"Mojtaba";
	}else{
		cout<<"Arpa";\
	}
}