#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int cnt[1000009],a[100009],b[1000000],mex,s[N],t;
int main(){
	int n; cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]); a[n+1]=1000000; 
	for(int i=1;i<=1000000;i++) b[i]=-114514;
	for(int i=1;i<=n;i++){
		s[++t]=i;
		for(int j=max(mex,0);j<=a[n+1];j++){
			if(cnt[j]==0&&j<a[i]){
				if(t!=0) cnt[b[s[t--]]=j]++;
				else{return puts("-1"),0;}
			}else if(cnt[j]==0&&j>=a[i]){
				mex=j;break;
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",(b[i]==-114514)?n+1:b[i]);
	return 0;
}