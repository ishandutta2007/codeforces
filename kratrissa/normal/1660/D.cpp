#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,a[N],s[N],ansl,ansr,ans;vector<int> pos;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);pos.clear(),pos.push_back(0),ans=0,ansl=0,ansr=n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)if(a[i]==0)pos.push_back(i);pos.push_back(n+1);
		for(int i=1;i<=n;i++)s[i]=s[i-1]+(a[i]==2||a[i]==-2);
		for(int k=0;k<pos.size()-1;k++)if(pos[k]+1<pos[k+1]){
			int cnt=0;
			for(int i=pos[k]+1;i<pos[k+1];i++)cnt+=(a[i]<0);
			if(cnt&1^1){if(s[pos[k+1]-1]-s[pos[k]]>ans)ansl=pos[k],ansr=n-pos[k+1]+1,ans=s[pos[k+1]-1]-s[pos[k]];continue;}
			int fir=0,lst=0;
			for(int i=pos[k]+1;i<pos[k+1];i++)if(a[i]<0){fir=i;break;}
			for(int i=pos[k+1]-1;i>pos[k];i--)if(a[i]<0){lst=i;break;}
			if(s[pos[k+1]-1]-s[fir]>ans)ansl=fir,ansr=n-pos[k+1]+1,ans=s[pos[k+1]-1]-s[fir];
			if(s[lst-1]-s[pos[k]]>ans)ansl=pos[k],ansr=n-lst+1,ans=s[lst-1]-s[pos[k]];
		}
		printf("%d %d\n",ansl,ansr);
	}
	return 0;
}